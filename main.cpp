/* Author   :   Dr. John Charlery
 * DATE     :   12 February, 2025
 *
 * Purpose:
 *
 * This program illustrates the usage of some of the tools withing wxWidgets.
 * In particular, it illustrates the usage of wxStaticText, wxTextCtrl, panel
 * and the passage of data to the text boxes.
 *
 */

/************************************************************************************
  Step 1: Always include the header file wx.h
*************************************************************************************/
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with
          the function to execute the program
*************************************************************************************
*************************************************************************************/
class ProjectApp : public wxApp {
  virtual bool OnInit();
};

/************************************************************************************
*************************************************************************************
   Step 3: Declare the inherited main frame class from wxFrame. In this class
           also will ALL the events handlers be declared
*************************************************************************************
*************************************************************************************/
class ProjectFrame : public wxFrame {
private:
  DECLARE_EVENT_TABLE() // To declare events items

public:
  ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

  // Functions for File Menu Items
  void OnOpenFile(wxCommandEvent &event);
  void OnDisplay(wxCommandEvent &event);
  void OnSave(wxCommandEvent &event);
  void OnSaveAs(wxCommandEvent &event);
  void OnExit(wxCommandEvent &event); // handle for Quit function

  // Function for Help Menu Item
  void OnAbout(wxCommandEvent &event);

  // ---etc. etc ---

  // Public attributes
  wxTextCtrl *MainEditBox;
  wxTextCtrl *filenameTextBox;

  wxString CurrentDocPath; // The Path to the file we have open
};

/************************************************************************************
*************************************************************************************
  Step 4. Declare the compiler directives
*************************************************************************************
*************************************************************************************/
DECLARE_APP(ProjectApp)   // Declare Application class
IMPLEMENT_APP(ProjectApp) // Create Application class object

enum {
  // File menu items
  ID_OpenFile = wxID_HIGHEST + 1, // File menu item
  ID_Display,
  ID_Save,
  ID_SaveAs,
  ID_Exit,

  // Help menu items
  ID_About,

  // ---etc. etc ---

};

BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// Events for the "File" menu items
EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile) // File Menu
EVT_MENU(ID_Display, ProjectFrame::OnDisplay)
EVT_MENU(ID_Save, ProjectFrame::OnSave)
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
EVT_MENU(ID_Exit, ProjectFrame::OnExit)

// ---etc. etc ---

END_EVENT_TABLE()

/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool ProjectApp::OnInit() {
  // Create the main application window
  ProjectFrame *frame = new ProjectFrame(wxT("COMP2611 - Data Structures"),
                                         wxPoint(50, 50), wxSize(840, 600));

  // Display the window
  frame->Show(TRUE);

  SetTopWindow(frame);

  return TRUE;
}

/************************************************************************************
*************************************************************************************
  Step 6:   Define the Constructor functions for the Frame class
*************************************************************************************
*************************************************************************************/
ProjectFrame::ProjectFrame(const wxString &title, const wxPoint &pos,
                           const wxSize &size)
    : wxFrame((wxFrame *)NULL, -1, title, pos, size) {
  // Set the frame icon - optional
  SetIcon(wxIcon(wxT("Icon.xpm")));

  // Create the main-menu items
  wxMenu *menuFile = new wxMenu;
  wxMenu *menuHelp = new wxMenu;

  // Add the main menu pointer for the Deque
  wxMenu *menuDeque = new wxMenu;

  // Create a Main menu bar
  wxMenuBar *menuBar = new wxMenuBar;

  // Append the main menu items to the Menu Bar
  menuBar->Append(menuFile, wxT("File"));
  menuBar->Append(menuHelp, wxT("Help"));

  // Append the sub-menu items to the File Main Menu item
  menuFile->Append(ID_OpenFile, wxT("&Open File..."),
                   wxT("Open an Existing file"));
  menuFile->Append(ID_Display, wxT("&Display File..."),
                   wxT("Display contents of opened file"));
  menuFile->Append(ID_Save, wxT("&Save"), wxT("Save opened file"));
  menuFile->Append(ID_SaveAs, wxT("Save &As..."),
                   wxT("Save display as a new file"));
  menuFile->Append(ID_Exit, wxT("E&xit"), wxT("Close and EXIT Program"));

  // Append the sub-menu items to the Help Main Menu item
  menuHelp->Append(ID_About, wxT("About"), wxT("About this program"));
  menuHelp->Append(ID_Exit, wxT("E&xit"), wxT("Close and EXIT Program"));

  // ... and now... attach this main menu bar to the frame
  SetMenuBar(menuBar);

  // Create a status bar just for fun
  CreateStatusBar(3);

  // Put something in the first section of the status bar
  SetStatusText(wxT("Ready..."));

  // Put something in the Second section of the status bar
  SetStatusText(wxT("    Wiley Coyote, Genius"), 1);

  // Put something in the Third section of the status bar
  SetStatusText(wxT("    123456789"), 2);

  // Set up the panel for data display
  //=========================================================================================
  //=========================== DO NOT CHANGE THE CODE IN THIS SECTION
  //======================
  //=========================================================================================

  wxPanel *panel = new wxPanel(this, -1);
  wxBoxSizer *vbox =
      new wxBoxSizer(wxVERTICAL); // Vertical sizer for main window
  wxBoxSizer *hbox1 =
      new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for main window

  // Add two textboxes to the panel for data display
  wxBoxSizer *hbox2 =
      new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for filename window
  wxBoxSizer *hbox3 =
      new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for display window

  wxStaticText *fileLabel = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
  wxStaticText *displayLabel =
      new wxStaticText(panel, wxID_ANY, wxT("Display"));

  // Initialize the filename textbox window
  filenameTextBox =
      new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));

  // Initialize the display window
  MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."),
                               wxPoint(-1, -1), wxSize(-1, -1),
                               wxTE_MULTILINE | wxTE_RICH);

  // Position the labels and textboxes in the panel
  hbox1->Add(fileLabel, 0, wxRIGHT, 8);
  hbox1->Add(filenameTextBox, 1);
  vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

  vbox->Add(-1, 10);
  hbox2->Add(displayLabel, 0);
  vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
  vbox->Add(-1, 10);

  hbox3->Add(MainEditBox, 1, wxEXPAND);
  vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

  vbox->Add(-1, 25);
  panel->SetSizer(vbox);

  Centre();
}

/************************************************************************************
*************************************************************************************
  Step 7:  Define member functions for the Frame class
*************************************************************************************
*************************************************************************************/

//===================================================================================
//=========== Definition for the File Functions
//=====================================
//===================================================================================

void ProjectFrame::OnOpenFile(wxCommandEvent &event) {
  // Creates a "open file" dialog with 3 file types
  wxFileDialog *OpenDialog = new wxFileDialog(
      this, (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
      (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files "
           "(*.*)|*.*")),
      wxFD_OPEN, wxDefaultPosition);

  if (OpenDialog->ShowModal() ==
      wxID_OK) // if the user click "Open" instead of "cancel"
  {
    // Sets our current document to the file the user selected
    CurrentDocPath = OpenDialog->GetPath();

    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);

    MainEditBox->LoadFile(CurrentDocPath); // Opens that file in the MainEditBox

    // Set the Title
    SetTitle(wxString(wxT("COMP2611 - Data Structures : 123456789")));
  }
}

void ProjectFrame::OnSave(wxCommandEvent &event) {
  // Save to the already-set path for the document
  MainEditBox->SaveFile(CurrentDocPath);
}

void ProjectFrame::OnSaveAs(wxCommandEvent &event) {
  wxFileDialog *SaveDialog = new wxFileDialog(
      this, (wxT("Save File As...?")), wxEmptyString, wxEmptyString,
      (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
      wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

  // Creates a Save Dialog with 4 file types
  if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
  {
    CurrentDocPath = SaveDialog->GetPath();

    // set the path of our current document to the file the user chose to save
    // under
    MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

    // Set the Title to reflect the file open
    SetTitle(wxString(wxT("COMP2611 - Data Structures : 123456789")));
  }
}

void ProjectFrame::OnDisplay(wxCommandEvent &event) {
  // Creates a "open file" dialog with 4 file types
  wxFileDialog *OpenDialog = new wxFileDialog(
      this, (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
      (wxT("Text files (*.txt)|*.txt|Data Files (*.dat)|*.dat|All files "
           "(*.*)|*.*")),
      wxFD_OPEN, wxDefaultPosition);

  MainEditBox->Clear();

  MainEditBox->LoadFile(CurrentDocPath);
}

void ProjectFrame::OnExit(wxCommandEvent &event) {
  wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
  Close(TRUE); // Close the window
}

void ProjectFrame::OnAbout(wxCommandEvent &event) {
  wxMessageBox(wxT("   Data Structures\n wxWidgets Exercise\n\tVersion 1.0"),
               wxT("About..."), wxOK | wxICON_INFORMATION, this);
}
