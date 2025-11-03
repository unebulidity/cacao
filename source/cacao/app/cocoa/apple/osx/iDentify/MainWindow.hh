//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: MainWindow.hh
///
/// Author: $author$
///   Date: 10/30/2025
//////////////////////////////////////////////////////////////////////////
#ifndef CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_MAINWINDOW_HH
#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_MAINWINDOW_HH

#include "cacao/app/cocoa/apple/osx/iDentify/iDentifyMain.hh"
#include "cacao/app/cocoa/apple/osx/iDentify/iDentifyMainWindow.hh"
#include "cacao/app/cocoa/apple/osx/iDentify/iDentifyMainView.hh"
#include "cacao/app/cocoa/apple/osx/iDentify/iDentifyControlView.hh"
#include "cacao/app/cocoa/iDentify/MainWindow.hh"
#include "cacao/cocoa/mt/apple/osx/Thread.hh"
#include "cacao/cocoa/mt/apple/osx/Semaphore.hh"
#include "cacao/cocoa/base/Waited.hh"

namespace cacao {
namespace app {
namespace cocoa {
namespace apple {
namespace osx {
namespace iDentify {

typedef ::cacao::cocoa::mt::apple::osx::Thread Thread;
///////////////////////////////////////////////////////////////////////
///  Class: ThreadRun
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS ThreadRun: public Thread::Run {
public:
    typedef Thread::Run Extends;

    typedef cacao::cocoa::mt::apple::osx::Semaphore Semaphore;
    typedef cacao::cocoa::Waited::WaitStatus WaitStatus;
    typedef cacao::cocoa::Waiter Waiter;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ThreadRun(iDentifyMainWindow* mainWindow)
    : m_mainWindow(mainWindow), m_done(false) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual RunStatus operator()() {

        LOG_DEBUG("for (bool done = false; !done;) {...");
        for (bool done = false; !done;) {

            LOG_DEBUG("try {...");
            try {
                LOG_DEBUG("waitr(m_updateFileHash)...");
                volatile Waiter waitr(m_updateFileHash);
                LOG_DEBUG("...waitr(m_updateFileHash)");
                
                LOG_DEBUG("(!(done = m_done))...");
                if (!(done = m_done)) {
                    LOG_DEBUG("[m_mainWindow performSelectorOnMainThread:@selector(updateFileHash:) withObject:m_mainWindow waitUntilDone:NO]...");
                    [m_mainWindow performSelectorOnMainThread:@selector(updateFileHash:) withObject:m_mainWindow waitUntilDone:NO];
                    LOG_DEBUG("...[m_mainWindow performSelectorOnMainThread:@selector(updateFileHash:) withObject:m_mainWindow waitUntilDone:NO]");
                } else {
                    LOG_DEBUG("...failed on (!(done = m_done))");
                }
            } catch (const WaitStatus& status) {
                LOG_ERROR("...catch (const WaitStatus& status) on waitr(m_updateFileHash)");
                done = true;
            }
            LOG_DEBUG("...} try");
        }
        LOG_DEBUG("...} for (bool done = false; !done;)");

        LOG_DEBUG("return RunSuccess...");
        return RunSuccess;
    }
    void Stop() {
        m_done = true;
        m_updateFileHash.Release();
        m_updateFileHash.Destroy();
    }
    void UpdateFileHash() {
        m_updateFileHash.Release();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    iDentifyMainWindow* m_mainWindow;
    bool m_done;
    Semaphore m_updateFileHash;
};

typedef ::cacao::app::cocoa::iDentify::MainWindow MainWindowExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainWindow: public MainWindowExtends {
public:
    typedef MainWindowExtends Extends;
    typedef MainWindow Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainWindow()
    : m_controlView(0),
      m_threadRun(0),
      m_thread(0) {
    }
    virtual ~MainWindow() {
        if (!(Fini())) {
            LOG_ERROR("...failed on Fini()");
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init(iDentifyMainWindow* mainWindow) {
        if ((mainWindow)) {
            if ((m_threadRun = new ThreadRun(mainWindow))) {
                if ((m_thread = new Thread(*m_threadRun))) {
                    return true;
                }
                delete m_threadRun;
                m_threadRun = 0;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool Fini() {
        bool success = true;
        if ((m_threadRun)) {
            m_threadRun->Stop();
        }
        if ((m_thread)) {
            try {
                delete m_thread;
            } catch (const Creator::Exception& e) {
                LOG_ERROR("...caught const Creator::Exception& e = " << e << " on delete m_thread");
                success = false;
            }
            m_thread = 0;
        }
        if ((m_threadRun)) {
            delete m_threadRun;
            m_threadRun = 0;
        }
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Hash() {
        String s;
        LOG_DEBUG("GetUser(s)...");
        if (GetUser(s)) {
            LOG_DEBUG("...User = \"" << s << "\"");
            if (0 < s.length()) {
                String text("{\"password\":{\"user\":\"");

                text.append(s);
                LOG_DEBUG("GetResource(s)...");
                if (GetResource(s)) {
                    LOG_DEBUG("...Resource = \"" << s << "\"");
                    if (0 < s.length()) {

                        text.append("\",\"resource\":\"");
                        text.append(s);
                        LOG_DEBUG("GetPassword(s)...");
                        if (GetPassword(s)) {
                            LOG_DEBUG("...Password = \"" << s << "\"");
                            if (0 < s.length()) {

                                text.append("\",\"password\":\"");
                                text.append(s);
                                text.append("\"}}");

                                LOG_DEBUG("GetHash(s)...");
                                if (GetHash(s)) {
                                    LOG_DEBUG("...Hash = \"" << s << "\"");
                                    if (0 < s.length()) {
                                        LOG_DEBUG("ClearHash()...");
                                        ClearHash();
                                    }
                                }
                                LOG_DEBUG("GetHashText(s)...");
                                if (GetHashText(s)) {
                                    LOG_DEBUG("...HashText = \"" << s << "\"");
                                    if (0 < s.length()) {

                                        LOG_DEBUG("GetHashFileName...");
                                        if (GetHashFileName(s)) {
                                            LOG_DEBUG("...HashFileName = \"" << s << "\"");
                                            if (0 < s.length()) {
                                                return HashFile();
                                            }
                                        }
                                        return HashText();
                                    } else {
                                        LOG_DEBUG("SetHashText(\"" << text << "\")...");
                                        SetHashText(text);
                                    }
                                }
                            } else {
                            }
                        }
                    } else {
                    }
                }
            } else {
            }
        }
        LOG_DEBUG("GetHashFileName...");
        if (GetHashFileName(s)) {
            LOG_DEBUG("...HashFileName = \"" << s << "\"");
            if (0 < s.length()) {
                return HashFile();
            }
        }
        LOG_DEBUG("GetHashText(s)...");
        if (GetHashText(s)) {
            LOG_DEBUG("...HashText = \"" << s << "\"");
            if (0 < s.length()) {
                return HashText();
            }
        }
        LOG_DEBUG("HashBlank()...");
        return HashBlank();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool HashFileUpdate() {
        return Extends::HashFileUpdate();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool HashCancel() {
        String s;
        LOG_DEBUG("GetHashText(s)...");
        if (GetHashText(s)) {
            LOG_DEBUG("...HashText = \"" << s << "\"");
            if (0 < s.length()) {
                LOG_DEBUG("ClearHashText()...");
                ClearHashText();
            }
        }
        LOG_DEBUG("GetHashFileName(s)...");
        if (GetHashFileName(s)) {
            LOG_DEBUG("...HashFileName = \"" << s << "\"");
            if (0 < s.length()) {
                LOG_DEBUG("ClearHashFileName()...");
                ClearHashFileName();
            }
        }
        return Extends::HashCancel();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool UpdateHash() {
        LOG_DEBUG("return Extends::UpdateHash()...");
        return Extends::UpdateHash();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual iDentifyControlView* SetControlView(iDentifyControlView* to) {
        return m_controlView = to;
    }
    virtual iDentifyControlView* GontrolView() const {
        return (iDentifyControlView*&)(m_controlView);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool PostUpdateFileHashEvent() {
        if ((m_thread) && (m_threadRun)) {
            m_threadRun->UpdateFileHash();
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ClearHashFileName() {
        if ((m_controlView)) {
            [m_controlView clearFile];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetHashFileName(const String& hashFileName) {
        if ((m_controlView)) {
            [m_controlView setText:hashFileName];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetHashFileName(String& fileName) {
        if ((m_controlView)) {
            [m_controlView getFile:fileName];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ClearHashText() {
        if ((m_controlView)) {
            [m_controlView clearText];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetHashText(const String& hashText) {
        if ((m_controlView)) {
            [m_controlView setText:hashText];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetHashText(String& hashText) {
        if ((m_controlView)) {
            [m_controlView getText:hashText];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetUser(String& text) {
        if ((m_controlView)) {
            [m_controlView getUser:text];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetResource(String& text) {
        if ((m_controlView)) {
            [m_controlView getResource:text];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetPassword(String& text) {
        if ((m_controlView)) {
            [m_controlView getPassword:text];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ShowHash(const String& hashX) {
        if ((m_controlView)) {
            [m_controlView setHash:hashX];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool ClearHash() {
        Extends::ClearHash();
        if ((m_controlView)) {
            String hashText;
            [m_controlView setHash:hashText];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetHash(String& text) {
        if ((m_controlView)) {
            [m_controlView getHash:text];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool HashIsUpperCase() {
        if ((m_controlView)) {
            if (([m_controlView upperChecked])) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ShowProgress(size_t maximum, size_t amount) {
        if ((m_controlView)) {
            [m_controlView showProgress:maximum amount:amount];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool UpdateProgress(size_t amount) {
        if ((m_controlView)) {
            [m_controlView updateProgress:amount];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool HideProgress() {
        if ((m_controlView)) {
            [m_controlView hideProgress];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    iDentifyControlView* m_controlView;
    ThreadRun* m_threadRun;
    Thread* m_thread;
};

} /// namespace iDentify 
} /// namespace osx 
} /// namespace apple 
} /// namespace cocoa 
} /// namespace app 
} /// namespace cacao 

#endif /// ndef CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_MAINWINDOW_HH

