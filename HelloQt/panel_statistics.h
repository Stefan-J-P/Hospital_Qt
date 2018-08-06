#ifndef PANEL_STATISTICS_H
#define PANEL_STATISTICS_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

class panel_statistics : public QWidget
{
    Q_OBJECT
public:
    explicit panel_statistics(QWidget *parent = 0);

signals:

public slots:

private:
    QTableWidget* table1_;

    QVBoxLayout* main_layout_;
    QHBoxLayout* table_layout1_;
};

#endif // PANEL_STATISTICS_H
