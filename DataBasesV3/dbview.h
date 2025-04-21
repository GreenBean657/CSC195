//
// Created by GreenBean on 4/19/25.
//


#include <computerpart.h>
#include <editorwidget.h>
#include <QtWidgets/QListView>


class DbView : public QListView {
    Q_OBJECT

public:
    EditorWidget *widget = nullptr;
    DbView(QWidget *parent = nullptr);

public slots:
    void createNew();
    void deleteSelected();

protected slots:
    void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;
    ComputerPart *itemFromIndex(const QModelIndex &index);
};


