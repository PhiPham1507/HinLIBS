#include "catalogueentrybutton.h"

CatalogueEntryButton::CatalogueEntryButton(int id, QWidget* parent) : QPushButton(parent), id(id) {};

int CatalogueEntryButton::getItemId() const
{
    return id;
}
