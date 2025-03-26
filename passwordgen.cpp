#include <wx/wxprec.h>
#include <wx/spinctrl.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class PasswordGenApp : public wxApp
{
public:
    virtual bool OnInit() override;
};

class PasswordGenFrame : public wxFrame
{
public:
    PasswordGenFrame();

private:
    void CreateControls();
    void BindEvents();

    wxSpinCtrl* m_passwordLenInput;
    wxCheckBox* m_useNumbersBox;
    wxCheckBox* m_useSpecialSymbBox;
    wxCheckBox* m_useRandomRegisterBox;
    wxStaticText* m_passwordResult;
    wxButton* m_generateBtn;

    void OnGenerateButtonClick(wxCommandEvent& event);
};

wxIMPLEMENT_APP(PasswordGenApp);

bool PasswordGenApp::OnInit()
{
    auto* frame = new PasswordGenFrame();
    frame->Show(true);
    return true;
}

PasswordGenFrame::PasswordGenFrame()
    : wxFrame(nullptr, wxID_ANY, wxString::FromUTF8("Генератор паролей"))
{
    CreateControls();
    BindEvents();
    Layout();
    Centre(wxBOTH);
}

void PasswordGenFrame::CreateControls()
{
    SetSizeHints(wxDefaultSize, wxDefaultSize);

    // Main sizer with 2 columns
    auto* mainSizer = new wxFlexGridSizer(0, 2, 0, 0);
    mainSizer->AddGrowableCol(0, 1);
    mainSizer->SetFlexibleDirection(wxBOTH);

    // Left column controls
    auto* leftColumn = new wxBoxSizer(wxVERTICAL);
    
    constexpr int MIN_LEN = 8, MAX_LEN = 25, DEFAULT_LEN = 8;
    m_passwordLenInput = new wxSpinCtrl(this, wxID_ANY, std::to_string(DEFAULT_LEN),
        wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, MIN_LEN, MAX_LEN, DEFAULT_LEN);
    leftColumn->Add(m_passwordLenInput, 0, wxALL | wxEXPAND, 5);

    m_useNumbersBox = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("Цифры"));
    leftColumn->Add(m_useNumbersBox, 0, wxALL, 5);

    m_useSpecialSymbBox = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("Спецсимволы"));
    leftColumn->Add(m_useSpecialSymbBox, 0, wxALL, 5);

    m_useRandomRegisterBox = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("Случайный регистр"));
    leftColumn->Add(m_useRandomRegisterBox, 0, wxALL, 5);

    mainSizer->Add(leftColumn, 1, wxEXPAND);

    // Right column controls
    auto* rightColumn = new wxBoxSizer(wxVERTICAL);

    m_passwordResult = new wxStaticText(this, wxID_ANY, "");
    m_passwordResult->SetFont(wxFontInfo().Bold());
    rightColumn->Add(m_passwordResult, 1, wxALL | wxEXPAND, 5);

    m_generateBtn = new wxButton(this, wxID_ANY, wxString::FromUTF8("Сгенерировать"));
    rightColumn->Add(m_generateBtn, 0, wxALL | wxALIGN_CENTER, 5);

    mainSizer->Add(rightColumn, 0, wxEXPAND);

    SetSizerAndFit(mainSizer);
}

void PasswordGenFrame::BindEvents()
{
    m_generateBtn->Bind(wxEVT_BUTTON, &PasswordGenFrame::OnGenerateButtonClick, this);
}

void PasswordGenFrame::OnGenerateButtonClick(wxCommandEvent& event)
{
    m_passwordResult->SetLabelText(wxString::FromUTF8("Clicked!"));
    Layout();
}