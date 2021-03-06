#ifndef XQCAMERA_H
#define XQCAMERA_H

// INCLUDES
#include <QObject>

// FORWARD DECLARATIONS
class XQCameraPrivate;
class QSize;
class QImage;

// CLASS DECLARATION
class XQCamera : public QObject
{
    Q_OBJECT
    
public:

    enum Error {
        NoError = 0,
        OutOfMemoryError,
        InUseError,
        NotReadyError,
        UnknownError = -1
    };
    
    XQCamera(QObject* parent = 0);
    ~XQCamera();

    bool open(int index = 0);
    void setCaptureSize(QSize size);
    static int camerasAvailable();
    XQCamera::Error error() const;
    
public Q_SLOTS:
    bool capture();
    void close();
    bool focus();
    void cancelFocus();
    void releaseImageBuffer();

Q_SIGNALS:
    void cameraReady();
    void focused();
    void captureCompleted(QByteArray imageData);
    void captureCompleted(QImage* image);
    void error(XQCamera::Error error);

private:
    friend class XQViewFinderWidgetPrivate;
    friend class XQCameraPrivate;
    XQCameraPrivate* d;
};

#endif // XQCAMERA_H

// End of file
