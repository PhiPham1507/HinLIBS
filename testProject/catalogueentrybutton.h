#ifndef CATALOGUEENTRYBUTTON_H
#define CATALOGUEENTRYBUTTON_H

#include <QPushButton>

class CatalogueEntryButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CatalogueEntryButton(int id,  QWidget* parent = nullptr);
    int getItemId() const;

private:
    int id = -1;
};

#endif // CATALOGUEENTRYBUTTON_H
