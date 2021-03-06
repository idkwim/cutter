#ifndef ANALTHREAD_H
#define ANALTHREAD_H

#include <QThread>

class CutterCore;
class MainWindow;
class OptionsDialog;

class AnalThread : public QThread
{
    Q_OBJECT
public:
    explicit AnalThread(OptionsDialog *parent = nullptr);
    ~AnalThread();

    void start(MainWindow *main, int level, QList<QString> advanced);
    void interruptAndWait();

    bool isInterrupted()
    {
        return interrupted;
    }

protected:
    void run();

    using QThread::start;

signals:
    void updateProgress(QString str);
    void openFileFailed();

private:
    int level;
    QList<QString> advanced;
    MainWindow *main;

    bool interrupted;
};

#endif // ANALTHREAD_H
