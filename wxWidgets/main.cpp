// ==============================

//       Encryption in C++

// ==============================

// This app allows basic file selection and visual triggers for encryption/decryption.

// You can implement actual file encryption using libraries like Crypto++, OpenSSL, or simple XOR.

#pragma once

#include <wx/wx.h>

#include <wx/filedlg.h>

#include <wx/filename.h>

#include <wx/artprov.h>

class MainFrame : public wxFrame

{

public:

    MainFrame(const wxString& title);

private:

    wxPanel* panel;

    wxButton* browseButton;

    wxButton* encryptButton;

    wxButton* decryptButton;

    wxString selectedFilePath;



    void OnBrowse(wxCommandEvent& event);

    void OnEncrypt(wxCommandEvent& event);

    void OnDecrypt(wxCommandEvent& event);



    wxDECLARE_EVENT_TABLE();

};

enum

{

    ID_Browse = 1,

    ID_Encrypt,

    ID_Decrypt

};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)

EVT_BUTTON(ID_Browse, MainFrame::OnBrowse)

EVT_BUTTON(ID_Encrypt, MainFrame::OnEncrypt)

EVT_BUTTON(ID_Decrypt, MainFrame::OnDecrypt)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)

    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 250))

{

    panel = new wxPanel(this, wxID_ANY);



    // Title Label Above Browse Button

    new wxStaticText(panel, wxID_ANY, "Encryption in C++", wxPoint(200, 100), wxDefaultSize, wxALIGN_LEFT);



    browseButton = new wxButton(panel, ID_Browse, " Browse", wxPoint(20, 20), wxSize(120, 40));

    browseButton->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_BUTTON));



    encryptButton = new wxButton(panel, ID_Encrypt, "Encrypt", wxPoint(20, 80), wxSize(120, 40));

    decryptButton = new wxButton(panel, ID_Decrypt, "Decrypt", wxPoint(160, 80), wxSize(120, 40));



    encryptButton->Hide();

    decryptButton->Hide();

}

void MainFrame::OnBrowse(wxCommandEvent& event)

{

    wxFileDialog openFileDialog(this, "Select a file", "", "",

        "All files (.)|.", wxFD_OPEN | wxFD_FILE_MUST_EXIST);



    if (openFileDialog.ShowModal() == wxID_OK)

    {

        selectedFilePath = openFileDialog.GetPath();

        encryptButton->Show();

        decryptButton->Show();

        Layout();  // Refresh layout to show buttons

    }

}

void MainFrame::OnEncrypt(wxCommandEvent& event)

{

    wxMessageBox("Encrypting: " + selectedFilePath, "Encrypt");

    // Encryption logic here

}

void MainFrame::OnDecrypt(wxCommandEvent& event)

{

    wxMessageBox("Decrypting: " + selectedFilePath, "Decrypt");

    // Decryption logic here

}

// App class to launch the frame

class MyApp : public wxApp

{

public:

    virtual bool OnInit()

    {

        MainFrame* frame = new MainFrame("File Encryptor");

        frame->Show(true);

        return true;

    }

};

wxIMPLEMENT_APP(MyApp);