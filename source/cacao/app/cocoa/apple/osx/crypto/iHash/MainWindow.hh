///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 9/3/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_MAINWINDOW_HH
#define _CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_MAINWINDOW_HH

#include "cacao/app/cocoa/apple/osx/crypto/iHash/iHashMain.hh"
#include "cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainWindow.hh"
#include "cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainView.hh"
#include "cacao/app/cocoa/apple/osx/crypto/iHash/iHashControlView.hh"
#include "cacao/app/cocoa/crypto/iHash/MainWindow.hh"
#include "cacao/cocoa/mt/apple/osx/Thread.hh"
#include "cacao/cocoa/mt/apple/osx/Semaphore.hh"
#include "cacao/cocoa/base/Waited.hh"

namespace cacao {
namespace app {
namespace cocoa {
namespace apple {
namespace osx {
namespace iHash {

typedef cacao::cocoa::mt::apple::osx::Thread Thread;
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
    ThreadRun(iHashMainWindow* mainWindow)
    : m_mainWindow(mainWindow), m_done(false) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual RunStatus operator()() {
        for (bool done = false; !done;) {
            LOG_DEBUG("waitr(m_updateFileHash)...");
            try {
                volatile Waiter waitr(m_updateFileHash);
                LOG_DEBUG("...waitr(m_updateFileHash)");
                if (!(done = m_done)) {
                    [m_mainWindow performSelectorOnMainThread:@selector(updateFileHash:)
                                  withObject:m_mainWindow waitUntilDone:NO];
                }
            } catch (const WaitStatus& status) {
                LOG_ERROR("...catch (const WaitStatus& status) on waitr(m_updateFileHash)");
                done = true;
            }
        }
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
    iHashMainWindow* m_mainWindow;
    bool m_done;
    Semaphore m_updateFileHash;
};

typedef cocoa::crypto::iHash::MainWindow MainWindowExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainWindow: public MainWindowExtends {
public:
    typedef MainWindowExtends Extends;
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
    virtual bool Init(iHashMainWindow* mainWindow) {
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
    virtual bool Hash() {
        String s;
        LOG_DEBUG("GetHashText(s)...");
        if (GetHashText(s)) {
            LOG_DEBUG("...text = \"" << s << "\"");
            if (0 < s.length()) {
                return HashText();
            }
        }
        LOG_DEBUG("GetHashFileName...");
        if (GetHashFileName(s)) {
            LOG_DEBUG("...file = \"" << s << "\"");
            if (0 < s.length()) {
                return HashFile();
            }
        }
        LOG_DEBUG("HashBlank()...");
        return HashBlank();
    }
    virtual bool HashFileUpdate() {
        return Extends::HashFileUpdate();
    }
    virtual bool HashCancel() {
        return Extends::HashCancel();
    }
    virtual bool UpdateHash() {
        return Extends::UpdateHash();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual iHashControlView* SetControlView(iHashControlView* to) {
        return m_controlView = to;
    }
    virtual iHashControlView* GontrolView() const {
        return (iHashControlView*&)(m_controlView);
    }
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
    virtual bool GetHashFileName(String& fileName) {
        if ((m_controlView)) {
            [m_controlView getFile:fileName];
            return true;
        }
        return false;
    }
    virtual bool GetHashText(String& hashText) {
        if ((m_controlView)) {
            [m_controlView getText:hashText];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ShowHash(const String& hashX) {
        if ((m_controlView)) {
            [m_controlView setHash:hashX];
            return true;
        }
        return false;
    }
    virtual bool ClearHash() {
        if ((m_controlView)) {
            String hashText;
            [m_controlView setHash:hashText];
            return true;
        }
        return false;
    }
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
    virtual bool ShowProgress(size_t maximum, size_t amount) {
        if ((m_controlView)) {
            [m_controlView showProgress:maximum amount:amount];
            return true;
        }
        return false;
    }
    virtual bool UpdateProgress(size_t amount) {
        if ((m_controlView)) {
            [m_controlView updateProgress:amount];
            return true;
        }
        return false;
    }
    virtual bool HideProgress() {
        if ((m_controlView)) {
            [m_controlView hideProgress];
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    iHashControlView* m_controlView;
    ThreadRun* m_threadRun;
    Thread* m_thread;
};

} // namespace iHash 
} // namespace osx 
} // namespace apple 
} // namespace cocoa 
} // namespace app 
} // namespace cacao 

#endif // _CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_MAINWINDOW_HH 
