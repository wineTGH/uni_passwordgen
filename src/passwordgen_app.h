#ifndef PASSWORDGEN_APP_H
#define PASSWORDGEN_APP_H

#include <wx/wx.h>

class PasswordGenApp : public wxApp {
   public:
    virtual bool OnInit() override;
};

#endif  // PASSWORDGEN_APP_H