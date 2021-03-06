#ifndef MWGUI_BOOKWINDOW_H
#define MWGUI_BOOKWINDOW_H

#include "windowbase.hpp"

#include "../mwworld/ptr.hpp"

#include <components/widgets/imagebutton.hpp>

namespace MWGui
{
    class BookWindow : public WindowBase
    {
        public:
            BookWindow();

            virtual void exit();

            void open(MWWorld::Ptr book);
            void setTakeButtonShow(bool show);
            void nextPage();
            void prevPage();
            void setInventoryAllowed(bool allowed);

        protected:
            void onNextPageButtonClicked (MyGUI::Widget* sender);
            void onPrevPageButtonClicked (MyGUI::Widget* sender);
            void onCloseButtonClicked (MyGUI::Widget* sender);
            void onTakeButtonClicked (MyGUI::Widget* sender);
            void onMouseWheel(MyGUI::Widget* _sender, int _rel);

            void updatePages();
            void clearPages();
            void adjustButton(Gui::ImageButton* button);

        private:
            Gui::ImageButton* mCloseButton;
            Gui::ImageButton* mTakeButton;
            Gui::ImageButton* mNextPageButton;
            Gui::ImageButton* mPrevPageButton;
            MyGUI::TextBox* mLeftPageNumber;
            MyGUI::TextBox* mRightPageNumber;
            MyGUI::Widget* mLeftPage;
            MyGUI::Widget* mRightPage;

            unsigned int mCurrentPage; // 0 is first page
            std::vector<MyGUI::Widget*> mPages;

            MWWorld::Ptr mBook;

            bool mTakeButtonShow;
            bool mTakeButtonAllowed;
    };

}

#endif
