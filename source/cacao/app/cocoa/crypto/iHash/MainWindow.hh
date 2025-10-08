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
///   Date: 9/2/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_APP_COCOA_CRYPTO_IHASH_MAINWINDOW_HH
#define _CACAO_APP_COCOA_CRYPTO_IHASH_MAINWINDOW_HH

#include "cacao/cocoa/crypto/hash/Base.hh"
#include <sys/stat.h>

#define CACAO_APP_COCOA_CRYPTO_IHASH_MAINWINDOW_FILE_BUFFER_SIZE (1024*64)

namespace cacao {
namespace app {
namespace cocoa {
namespace crypto {
namespace iHash {

typedef ImplementBase MainWindowExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TExtends = MainWindowExtends>
class _EXPORT_CLASS MainWindowT: public TExtends {
public:
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainWindowT()
    : m_hash(cacao::cocoa::crypto::hash::Implement::TheDerived()),
      m_file(0),
      m_fileSize(0),
      m_fileAmount(0),
      m_fileBufferLength(0),
      m_fileBufferSize(CACAO_APP_COCOA_CRYPTO_IHASH_MAINWINDOW_FILE_BUFFER_SIZE) {
    }
    virtual ~MainWindowT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t HashSize() const {
        return m_hash.hash_size();
    }
    virtual const char* HashName() const {
        return m_hash.name();
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetHashText(String& hashText) { return true; }
    virtual bool GetHashFileName(String& fileName) { return true; }
    virtual bool PostUpdateFileHashEvent() { return true; }
    virtual bool ShowHash(const String& hashX) { return true; }
    virtual bool ClearHash() { return true; }
    virtual bool HashIsUpperCase() { return false; }
    virtual bool ShowProgress(size_t maximum, size_t amount) { return true; }
    virtual bool UpdateProgress(size_t amount) { return true; }
    virtual bool HideProgress() { return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool HashText() {
        CloseFile();
        if ((ClearHash())) {
            if ((BeginHash())) {
                String textString;
                if ((GetHashText(textString))) {
                    const char* textChars;
                    size_t textLength;
                    if ((0 < (textLength = textString.length()))
                        && (textChars = textString.chars())) {
                        if ((Hash(textChars, textLength))) {
                            EndHash();
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    virtual bool HashFile() {
        CloseFile();
        if ((ClearHash())) {
            if ((BeginHash())) {
                String fileString;
                if ((GetHashFileName(fileString))) {
                    const char* chars;
                    if ((chars = fileString.has_chars())) {
                        int err;
                        struct stat st;
                        if (!(err = stat(chars, &st))) {
                            m_fileSize = st.st_size;
                        } else {
                            LOG_DEBUG("unable to stat \"" << chars << "\"");
                        }
                        if ((m_file = fopen(chars, "rb"))) {
                            HashFileUpdate(true);
                        } else {
                            LOG_DEBUG("unable to open \"" << chars << "\"");
                        }
                    }
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool HashFileUpdate(bool isShow = false) {
        if ((m_file)) {
            m_fileBuffer[m_fileBufferSize-1] = 0;
            if (0 < (m_fileBufferLength = fread(m_fileBuffer, 1,m_fileBufferSize-1, m_file))) {
                if ((Hash(m_fileBuffer, m_fileBufferLength))) {
                    if ((m_fileBufferSize-1) > m_fileBufferLength) {
                        EndHash();
                    } else {
                        if (isShow) {
                            ShowProgress();
                        } else {
                            UpdateProgress();
                        }
                        PostUpdateFileHashEvent();
                        return true;
                    }
                }
            } else {
                EndHash();
            }
            CloseFile();
            return true;
        }
        return false;
    }
    virtual bool HashBlank() {
        LOG_DEBUG("CloseFile()...");
        CloseFile();
        LOG_DEBUG("ClearHash...");
        if ((ClearHash())) {
            LOG_DEBUG("BeginHash...");
            if ((BeginHash())) {
                LOG_DEBUG("EndHash...");
                EndHash();
                return true;
            }
        }
        return false;
    }
    virtual bool HashCancel() {
        CloseFile();
        ClearHash();
        return true;
    }
    virtual bool CloseFile() {
        HideProgress();
        if ((m_file)) {
            fclose(m_file);
            m_file = 0;
            m_fileSize = 0;
            m_fileAmount = 0;
        }
        return false;
    }
    virtual bool ShowProgress() {
        if ((0 < (m_fileSize))) {
            if ((ShowProgress(m_fileSize, m_fileAmount += m_fileBufferLength))) {
                return true;
            }
        }
        return false;
    }
    virtual bool UpdateProgress() {
        if ((0 < (m_fileSize))) {
            UpdateProgress(m_fileAmount += m_fileBufferLength);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool BeginHash() {
        ssize_t hashSize = 0;
        if ((0 < (hashSize = m_hash.hash_size()))
            && (0 < (m_hashArray.set_length(hashSize)))
            && (0 <= (m_hash.initialize()))) {
            return true;
        }
        return false;
    }
    virtual bool Hash(const void* in, ssize_t inlen) {
        if (0 <= (m_hash.hash(in, inlen))) {
            return true;
        }
        return false;
    }
    virtual bool EndHash() {
        if (0 < (m_hash.finalize
            (m_hashArray.elements(), m_hashArray.length()))) {
            UpdateHash();
            return true;
        }
        return false;
    }
    virtual bool UpdateHash() {
        String hashXString;
        const char* hashChars;
        size_t hashLength;
        if ((hashChars = (m_hashArray.elements()))
            && ((hashLength = m_hashArray.length()))) {
            hashXString.appendx(hashChars, hashLength, HashIsUpperCase());
            LOG_DEBUG("ShowHash(hashXString = \"" << hashXString << "\")...");
            ShowHash(hashXString);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    cacao::cocoa::crypto::hash::Implement &m_hash;
    xos::base::char_array m_hashArray;
    FILE* m_file;
    size_t m_fileSize;
    size_t m_fileAmount;
    size_t m_fileBufferLength;
    size_t m_fileBufferSize;
    uint8_t m_fileBuffer[CACAO_APP_COCOA_CRYPTO_IHASH_MAINWINDOW_FILE_BUFFER_SIZE];
};
typedef MainWindowT<> MainWindow;

} // namespace iHash 
} // namespace crypto 
} // namespace cocoa 
} // namespace app 
} // namespace cacao 

#endif // _CACAO_APP_COCOA_CRYPTO_IHASH_MAINWINDOW_HH 
