#ifndef PASSWORDGEN_FRAME_H
#define PASSWORDGEN_FRAME_H

#include <wx/wx.h>
#include <wx/spinctrl.h>

class PasswordGenFrame : public wxFrame
{
public:
    PasswordGenFrame();

private:
    void CreateControls();
    void BindEvents();

    // UI Controls
    wxSpinCtrl* m_passwordLenInput;
    wxCheckBox* m_useNumbersBox;
    wxCheckBox* m_useSpecialSymbBox;
    wxCheckBox* m_useRandomRegisterBox;
    wxStaticText* m_passwordResult;
    wxButton* m_generateBtn;

    // Event handlers
    void OnGenerateButtonClick(wxCommandEvent& event);
};

#endif // PASSWORDGEN_FRAME_H