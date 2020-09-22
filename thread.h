#ifndef THREAD_H
#define THREAD_H
#include <QThread>

/// Inherit from QT Thread class
class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent =0);
    void Progress();
    void run();
    void stop();



signals:
    void ValueChanged(const int);

private:
    bool status=false;
};

#endif // THREAD_H
