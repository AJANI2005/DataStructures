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

// include  additional header files
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include "Deque.h"
#include "PQueue.h"
#include "Queue.h"
#include "Stack.h"

// Define global data structures
Queue *queue = new Queue();
Stack *stack = new Stack();
PQueue *pqueue = new PQueue();
Deque *deque = new Deque();

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
  void OnCreate_Queue(wxCommandEvent &event);
  void OnDisplayAll_Queue(wxCommandEvent &event);
  void OnShowHead_Queue(wxCommandEvent &event);
  void OnShowTail_Queue(wxCommandEvent &event);
  void OnDequeue_Queue(wxCommandEvent &event);

  void OnCreate_Deque(wxCommandEvent &event);
  void OnDisplayAll_Deque(wxCommandEvent &event);
  void OnShowHead_Deque(wxCommandEvent &event);
  void OnShowTail_Deque(wxCommandEvent &event);
  void OnDequeueHead_Deque(wxCommandEvent &event);
  void OnDequeueTail_Deque(wxCommandEvent &event);

  void OnCreate_PQueue(wxCommandEvent &event);
  void OnDisplayAll_PQueue(wxCommandEvent &event);
  void OnShowHead_PQueue(wxCommandEvent &event);
  void OnShowTail_PQueue(wxCommandEvent &event);
  void OnDequeue_PQueue(wxCommandEvent &event);

  void OnCreate_Stack(wxCommandEvent &event);
  void OnPop_Stack(wxCommandEvent &event);
  void OnDisplayAll_Stack(wxCommandEvent &event);
  void OnShowHead_Stack(wxCommandEvent &event);
  void OnShowTail_Stack(wxCommandEvent &event);

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
  ID_Create_Queue,
  ID_DisplayAll_Queue,
  ID_ShowHead_Queue,
  ID_ShowTail_Queue,
  ID_Dequeue_Queue,

  ID_Create_Deque,
  ID_DisplayAll_Deque,
  ID_ShowHead_Deque,
  ID_ShowTail_Deque,
  ID_DequeueHead_Deque,
  ID_DequeueTail_Deque,

  ID_Create_PQueue,
  ID_DisplayAll_PQueue,
  ID_ShowHead_PQueue,
  ID_ShowTail_PQueue,
  ID_Dequeue_PQueue,

  ID_Create_Stack,
  ID_Pop_Stack,
  ID_DisplayAll_Stack,
  ID_ShowHead_Stack,
  ID_ShowTail_Stack,
};

BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// Events for the "File" menu items
EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile) // File Menu
EVT_MENU(ID_Display, ProjectFrame::OnDisplay)
EVT_MENU(ID_Save, ProjectFrame::OnSave)
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
EVT_MENU(ID_Exit, ProjectFrame::OnExit)

// ---etc. etc ---
// Events for Queue menu items
EVT_MENU(ID_Create_Queue, ProjectFrame::OnCreate_Queue)
EVT_MENU(ID_DisplayAll_Queue, ProjectFrame::OnDisplayAll_Queue)
EVT_MENU(ID_ShowHead_Queue, ProjectFrame::OnShowHead_Queue)
EVT_MENU(ID_ShowTail_Queue, ProjectFrame::OnShowTail_Queue)
EVT_MENU(ID_Dequeue_Queue, ProjectFrame::OnDequeue_Queue)

// Events for Deque menu items
EVT_MENU(ID_Create_Deque, ProjectFrame::OnCreate_Deque)
EVT_MENU(ID_DisplayAll_Deque, ProjectFrame::OnDisplayAll_Deque)
EVT_MENU(ID_ShowHead_Deque, ProjectFrame::OnShowHead_Deque)
EVT_MENU(ID_ShowTail_Deque, ProjectFrame::OnShowTail_Deque)
EVT_MENU(ID_DequeueHead_Deque, ProjectFrame::OnDequeueHead_Deque)
EVT_MENU(ID_DequeueTail_Deque, ProjectFrame::OnDequeueTail_Deque)

// Events for Priority Queue menu items
EVT_MENU(ID_Create_PQueue, ProjectFrame::OnCreate_PQueue)
EVT_MENU(ID_DisplayAll_PQueue, ProjectFrame::OnDisplayAll_PQueue)
EVT_MENU(ID_ShowHead_PQueue, ProjectFrame::OnShowHead_PQueue)
EVT_MENU(ID_ShowTail_PQueue, ProjectFrame::OnShowTail_PQueue)
EVT_MENU(ID_Dequeue_PQueue, ProjectFrame::OnDequeue_PQueue)

// Events for Stack menu items
EVT_MENU(ID_Create_Stack, ProjectFrame::OnCreate_Stack)
EVT_MENU(ID_Pop_Stack, ProjectFrame::OnPop_Stack)
EVT_MENU(ID_DisplayAll_Stack, ProjectFrame::OnDisplayAll_Stack)
EVT_MENU(ID_ShowHead_Stack, ProjectFrame::OnShowHead_Stack)
EVT_MENU(ID_ShowTail_Stack, ProjectFrame::OnShowTail_Stack)
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

void ProjectFrame::OnCreate_Queue(wxCommandEvent &event) {
  ifstream infile(CurrentDocPath.mb_str());
  if (!infile.is_open()) {
    wxLogMessage("Error: Could not open file");
    return;
  }
  string month, artist, title, recordLabel, heading;
  int year, weeks;
  char asterisk;
  getline(infile, heading);

  while (getline(infile, month, '*')) {
    infile >> year;
    infile >> asterisk;
    getline(infile, artist, '*');
    getline(infile, title, '*');
    getline(infile, recordLabel, '*');
    infile >> weeks;

    // Enqueue the data into the queue
    queue->enqueue(Node(month, year, artist, title, recordLabel, weeks));

    // To handle the newline after each record
    infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  wxLogMessage("Queue Created");
  infile.close();
}

void ProjectFrame::OnDisplayAll_Queue(wxCommandEvent &event) {
  string records = queue->displayAll();
  MainEditBox->Clear();
  MainEditBox->AppendText(wxString::FromUTF8(records));
}

void ProjectFrame::OnShowHead_Queue(wxCommandEvent &event) {}

void ProjectFrame::OnShowTail_Queue(wxCommandEvent &event) {}

void ProjectFrame::OnDequeue_Queue(wxCommandEvent &event) {}

void ProjectFrame::OnCreate_Deque(wxCommandEvent &event) {}

void ProjectFrame::OnDisplayAll_Deque(wxCommandEvent &event) {}

void ProjectFrame::OnShowHead_Deque(wxCommandEvent &event) {}

void ProjectFrame::OnShowTail_Deque(wxCommandEvent &event) {}

void ProjectFrame::OnDequeueHead_Deque(wxCommandEvent &event) {}

void ProjectFrame::OnDequeueTail_Deque(wxCommandEvent &event) {}

void ProjectFrame::OnCreate_PQueue(wxCommandEvent &event) {}

void ProjectFrame::OnDisplayAll_PQueue(wxCommandEvent &event) {}

void ProjectFrame::OnShowHead_PQueue(wxCommandEvent &event) {}

void ProjectFrame::OnShowTail_PQueue(wxCommandEvent &event) {}

void ProjectFrame::OnDequeue_PQueue(wxCommandEvent &event) {}

void ProjectFrame::OnCreate_Stack(wxCommandEvent &event) {}

void ProjectFrame::OnPop_Stack(wxCommandEvent &event) {}

void ProjectFrame::OnDisplayAll_Stack(wxCommandEvent &event) {}

void ProjectFrame::OnShowHead_Stack(wxCommandEvent &event) {}

void ProjectFrame::OnShowTail_Stack(wxCommandEvent &event) {}

/************************************************************************************
*************************************************************************************
  Step 6:   Define the Constructor functions for the Frame class
*************************************************************************************
*************************************************************************************/
ProjectFrame::ProjectFrame(const wxString &title, const wxPoint &pos,
                           const wxSize &size)
    : wxFrame((wxFrame *)NULL, -1, title, pos, size) {
  // Set the frame icon - optional
  /*SetIcon(wxIcon(wxT("Icon.xpm")));*/

  // Create the main-menu items

  // Create a Main menu bar
  wxMenuBar *menuBar = new wxMenuBar;

  // Create menus
  wxMenu *menuFile = new wxMenu;
  wxMenu *menuHelp = new wxMenu;

  // Add the main menu pointer for the Queue
  wxMenu *menuQueue = new wxMenu;
  // Add the main menu pointer for the Deque
  wxMenu *menuDeque = new wxMenu;
  // Add the main menu pointer for the PQueue
  wxMenu *menuPQueue = new wxMenu;
  // Add the main menu pointer for the Stack
  wxMenu *menuStack = new wxMenu;

  // Append the menu items for the adts
  menuQueue->Append(ID_Create_Queue, wxT("Create Queue"),
                    wxT("Create a queue"));
  menuQueue->Append(ID_DisplayAll_Queue, wxT("Display All"),
                    wxT("Display all elements in the queue"));
  menuQueue->Append(ID_ShowHead_Queue, wxT("Show Head"),
                    wxT("Show the front element of the queue"));
  menuQueue->Append(ID_ShowTail_Queue, wxT("Show Tail"),
                    wxT("Show the rear element of the queue"));
  menuQueue->Append(ID_Dequeue_Queue, wxT("Dequeue"),
                    wxT("Remove the front element from the queue"));

  menuDeque->Append(ID_Create_Deque, wxT("Create Deque"),
                    wxT("Create a deque"));
  menuDeque->Append(ID_DisplayAll_Deque, wxT("Display All"),
                    wxT("Display all elements in the deque"));
  menuDeque->Append(ID_ShowHead_Deque, wxT("Show Head"),
                    wxT("Show the front element of the deque"));
  menuDeque->Append(ID_ShowTail_Deque, wxT("Show Tail"),
                    wxT("Show the rear element of the deque"));
  menuDeque->Append(ID_DequeueHead_Deque, wxT("Dequeue Head"),
                    wxT("Remove the front element from the deque"));
  menuDeque->Append(ID_DequeueTail_Deque, wxT("Dequeue Tail"),
                    wxT("Remove the rear element from the deque"));

  menuPQueue->Append(ID_Create_PQueue, wxT("Create PQ"),
                     wxT("Create a priority queue"));
  menuPQueue->Append(ID_DisplayAll_PQueue, wxT("Display All"),
                     wxT("Display all elements in the priority queue"));
  menuPQueue->Append(
      ID_ShowHead_PQueue, wxT("Show Head"),
      wxT("Show the highest-priority element in the priority queue"));
  menuPQueue->Append(
      ID_ShowTail_PQueue, wxT("Show Tail"),
      wxT("Show the lowest-priority element in the priority queue"));
  menuPQueue->Append(
      ID_Dequeue_PQueue, wxT("Dequeue"),
      wxT("Remove the highest-priority element from the priority queue"));

  menuStack->Append(ID_Create_Stack, wxT("Create Stack"),
                    wxT("Create a stack"));
  menuStack->Append(ID_Pop_Stack, wxT("Pop"),
                    wxT("Remove and display the top element from the stack"));
  menuStack->Append(ID_DisplayAll_Stack, wxT("Display All"),
                    wxT("Display all elements in the stack"));
  menuStack->Append(ID_ShowHead_Stack, wxT("Show Head"),
                    wxT("Show the top element of the stack"));
  menuStack->Append(ID_ShowTail_Stack, wxT("Show Tail"),
                    wxT("Show the bottom element of the stack"));

  // Append the main menu items to the Menu Bar
  menuBar->Append(menuFile, wxT("File"));

  // Append the abstract data types to the Menu Bar
  menuBar->Append(menuQueue, wxT("Queue"));
  menuBar->Append(menuDeque, wxT("Deque"));
  menuBar->Append(menuPQueue, wxT("Priority Queue"));
  menuBar->Append(menuStack, wxT("Stack"));

  menuBar->Append(menuHelp, wxT("Help"));
  // Create sub menus for adts
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
  SetStatusText(wxT("    Ajani Small"), 1);

  // Put something in the Third section of the status bar
  SetStatusText(wxT("    400017967"), 2);

  // Set up the panel for data display
  //
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
