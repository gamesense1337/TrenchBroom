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
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TrenchBroom_GamesPreferencePane
#define TrenchBroom_GamesPreferencePane

#include "View/PreferencePane.h"

class QLineEdit;
class QPushButton;
class QStackedWidget;
class QFormLayout;

namespace TrenchBroom {
    namespace View {
        class GameListBox;
        class GamePreferencePane;

        class GamesPreferencePane : public PreferencePane {
            Q_OBJECT
        private:
            GameListBox* m_gameListBox;
            QStackedWidget* m_stackedWidget;
            QWidget* m_defaultPage;
            /**
             * Regenerated on every selection change
             */
            GamePreferencePane* m_curraentGamePage;
            QString m_currentGame;
        public:
            explicit GamesPreferencePane(QWidget* parent = nullptr);
        private:
            void createGui();
        private:
            bool doCanResetToDefaults() override;
            void doResetToDefaults() override;
            void doUpdateControls() override;
            bool doValidate() override;
        };

        /**
         * Widget for configuring a single game.
         */
        class GamePreferencePane : public QWidget {
            Q_OBJECT
        private:
            std::string m_gameName;
            QLineEdit* m_gamePathText;
            QPushButton* m_chooseGamePathButton;
            std::vector<std::tuple<std::string, QLineEdit*>> m_toolPathEditors;
        public:
            explicit GamePreferencePane(const std::string& gameName, QWidget* parent = nullptr);
        private:
            void createGui();
        private:
            void currentGameChanged(const QString& gameName);
            void chooseGamePathClicked();
            void updateGamePath(const QString& str);
            void configureEnginesClicked();
        public:
            void updateControls();
        };
    }
}

#endif /* defined(TrenchBroom_GamesPreferencePane) */
