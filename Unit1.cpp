//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	std::wstring dir = ExtractFilePath(Application->ExeName).c_str();

        TOpenDialog *openDlg = new TOpenDialog(this);

        openDlg->Title= L"Open";
	openDlg->Filter="txt files (*.txt)";
	openDlg->Execute();

	if(openDlg->FileName.Length() == 0) return;

        OutputDebugString(openDlg->FileName.w_str());

        delete openDlg;

	std::ifstream infile(openDlg->FileName.w_str());
        std::string line;
	while (std::getline(infile, line))
	{
	    OutputDebugStringA(line.c_str());
	}
        infile.close();

return ;
       OutputDebugString(RichEdit1->Text.w_str());
       char *pAniFilename = NULL;
       WCharTochar(RichEdit1->Text.w_str(), &pAniFilename);

       RichEdit2->Text = pAniFilename;
       delete pAniFilename;
}
//---------------------------------------------------------------------------
////////////////////////////////////////////////////////////////
//	char *pAniFilename = NULL;
//	SYTool::Instance()->WCharTochar(appPath.c_str(), &pAniFilename);
//  delete pAniFilename;
void TForm1::WCharTochar(const wchar_t *source, char **dest)
{
	*dest = (char *)new char[2 * wcslen(source)+1] ;
	memset(*dest , 0 , 2 * wcslen(source)+1 );

    int   nLen   =   (int)wcslen(source)+1;
	WideCharToMultiByte(CP_ACP,   0,   source,   nLen,   *dest,   2*nLen,   NULL,   NULL);
	//OutputDebugStringA((*dest));

}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
      RichEdit1->Text = "";
      RichEdit2->Text =  "";
}
//---------------------------------------------------------------------------

