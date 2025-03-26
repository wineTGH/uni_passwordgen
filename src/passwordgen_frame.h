#ifndef PASSWORDGEN_FRAME_H
#define PASSWORDGEN_FRAME_H

#include <wx/clipbrd.h>
#include <wx/spinctrl.h>
#include <wx/wx.h>

class PasswordGenFrame : public wxFrame {
   public:
    PasswordGenFrame();

   private:
    void CreateControls();
    void BindEvents();

    // UI Элементы
    wxSpinCtrl* m_passwordLenInput;
    wxCheckBox* m_useNumbersBox;
    wxCheckBox* m_useSpecialSymbBox;
    wxCheckBox* m_useRandomRegisterBox;
    wxStaticText* m_passwordResult;
    wxButton* m_generateBtn;

    // Обработчики событий
    void OnGenerateButtonClick(wxCommandEvent& event);
    void OnPasswordResultClick(wxMouseEvent& event);
};

#endif  // PASSWORDGEN_FRAME_H