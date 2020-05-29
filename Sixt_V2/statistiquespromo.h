#ifndef STATISTIQUESPROMO_H
#define STATISTIQUESPROMO_H

#include <QWidget>

namespace Ui {
class StatistiquesPromo;
}

class StatistiquesPromo : public QWidget
{
    Q_OBJECT

public:
    explicit StatistiquesPromo(QWidget *parent = nullptr);
    ~StatistiquesPromo();

private:
    Ui::StatistiquesPromo *ui;
};

#endif // STATISTIQUESPROMO_H
