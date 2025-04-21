//
// Created by GreenBean on 4/19/25.
//

#include "editorwidget.h"
#include "gpu.h"

void EditorWidget::setSpecializedCheckbox(Qt::CheckState state) {
  if (QObject::sender()->objectName() == "gpuTest") {
    auto computerPart = dynamic_cast<GPU *>(part);
    if (state == Qt::CheckState::Checked) {
      computerPart->setState = true;
    } else {
      computerPart->setState = false;
    }
  }
}