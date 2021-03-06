#include "recordstatusdelegate.hpp"

#include <QPainter>
#include <QApplication>
#include <QUndoStack>

#include "../../model/settings/usersettings.hpp"
#include "../../model/world/columns.hpp"

CSVWorld::RecordStatusDelegate::RecordStatusDelegate(const ValueList& values,
                                                     const IconList & icons,
                                                     CSMDoc::Document& document, QObject *parent)
    : DataDisplayDelegate (values, icons, document,
                           "Display Format", "Record Status Display",
                           parent)
{}

CSVWorld::CommandDelegate *CSVWorld::RecordStatusDelegateFactory::makeDelegate (
    CSMDoc::Document& document, QObject *parent) const
{
    return new RecordStatusDelegate (mValues, mIcons, document, parent);
}

CSVWorld::RecordStatusDelegateFactory::RecordStatusDelegateFactory()
{
    std::vector<std::string> enums =
        CSMWorld::Columns::getEnums (CSMWorld::Columns::ColumnId_Modification);

    static const char *sIcons[] =
    {
        ":./base.png", ":./modified.png", ":./added.png", ":./removed.png", ":./removed.png", 0
    };

    for (int i=0; sIcons[i]; ++i)
        add (i, enums.at (i).c_str(), sIcons[i]);
}
