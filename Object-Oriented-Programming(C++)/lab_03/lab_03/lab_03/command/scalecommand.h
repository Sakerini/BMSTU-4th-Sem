#ifndef LAB_03_SCALECOMMAND_H
#define LAB_03_SCALECOMMAND_H

#include "iappcommand.h"

class ScaleCommand final : public IAppCommand {
public:
    ScaleCommand() {};
    explicit ScaleCommand(std::shared_ptr<SceneObjectComposite> &model);

    void execute(Argument arg) override;
};

#endif
