#ifndef LOGGING_H
#define LOGGING_H

#include <QDialog>

namespace Ui {
class logging;
}

class logging : public QDialog
{
    Q_OBJECT

public:
    explicit logging(QWidget *parent = nullptr);
    ~logging();

private:
    Ui::logging *ui;
};

#endif // LOGGING_H
