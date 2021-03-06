/*
 Copyright (C) 2010-2017 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#include "FindContainerVisitor.h"

#include "Model/GroupNode.h"
#include "Model/EntityNode.h"
#include "Model/LayerNode.h"
#include "Model/WorldNode.h"

namespace TrenchBroom {
    namespace Model {
        void FindContainerVisitor::doVisit(WorldNode* world) {
            setResult(world);
            cancel();
        }

        void FindContainerVisitor::doVisit(LayerNode* layer) {
            setResult(layer);
            cancel();
        }

        void FindContainerVisitor::doVisit(GroupNode* group) {
            setResult(group);
            cancel();
        }

        void FindContainerVisitor::doVisit(EntityNode* entity) {
            setResult(entity);
            cancel();
        }

        void FindContainerVisitor::doVisit(BrushNode*) {}
    }
}
