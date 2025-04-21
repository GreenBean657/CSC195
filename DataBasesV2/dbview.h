#include <computerpart.h>
#include <editorwidget.h>
#include <QtWidgets/QListView>


class DbView final : public QListView {
    Q_OBJECT

public:
    EditorWidget *widget = nullptr;
    explicit DbView(QWidget *parent = nullptr);

public slots:
    void createNewCPU();
    void createNewGPU();
    void createNewRAM();
    void deleteSelected();

protected slots:
    void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;
    ComputerPart *itemFromIndex(const QModelIndex &index);
};


