#include "passwordgen_app.h"

#include "passwordgen_frame.h"

wxIMPLEMENT_APP(PasswordGenApp);

bool PasswordGenApp::OnInit() {
    auto* frame = new PasswordGenFrame();
    frame->Show(true);
    return true;
}