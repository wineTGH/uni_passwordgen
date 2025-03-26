// wxWidgets "Hello World" Program
 
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/spinctrl.h>
#include <iostream>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
 
class PasswordGenApp : public wxApp
{
public:
    virtual bool OnInit();
};
 
class PasswordGenFrame : public wxFrame
{
public:
    PasswordGenFrame();
 
protected:
    wxSpinCtrl* password_len_input;
    wxCheckBox* use_numbers_box;
    wxCheckBox* use_special_symb_box;
    wxCheckBox* use_random_register_box;
    wxStaticText* password_result;
    wxButton* generate_btn;

    virtual void OnGenerateButtonClick( wxCommandEvent& event );
};
 
wxIMPLEMENT_APP(PasswordGenApp);
 
bool PasswordGenApp::OnInit()
{
    PasswordGenFrame *frame = new PasswordGenFrame();
    frame->Show(true);
    return true;
}
 
PasswordGenFrame::PasswordGenFrame()
    : wxFrame(NULL, wxID_ANY, wxString::FromUTF8("Генератор паролей"))
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	password_len_input = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 8, 25, 8 );
	bSizer3->Add( password_len_input, 0, wxALL|wxEXPAND, 5 );

	use_numbers_box = new wxCheckBox( this, wxID_ANY, wxString::FromUTF8("Цифры"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( use_numbers_box, 0, wxALL, 5 );

	use_special_symb_box = new wxCheckBox( this, wxID_ANY, wxString::FromUTF8("Спецсимволы"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( use_special_symb_box, 0, wxALL, 5 );

	use_random_register_box = new wxCheckBox( this, wxID_ANY, wxString::FromUTF8("Случайный регистр"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( use_random_register_box, 0, wxALL, 5 );


	fgSizer1->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	password_result = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	password_result->Wrap( 1 );
	password_result->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer4->Add( password_result, 1, wxALL|wxEXPAND, 5 );

	generate_btn = new wxButton( this, wxID_ANY, wxString::FromUTF8("Сгенерировать"), wxDefaultPosition, wxDefaultSize, 0 );
    generate_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PasswordGenFrame::OnGenerateButtonClick ), NULL, this );
	bSizer4->Add( generate_btn, 0, wxALL, 5 );


	fgSizer1->Add( bSizer4, 0, wxEXPAND, 5 );


	this->SetSizer( fgSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

void PasswordGenFrame::OnGenerateButtonClick( wxCommandEvent& event ) { 
    password_result->SetLabel(wxString::FromUTF8("Clicked!")); 
}