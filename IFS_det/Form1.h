#pragma once
#include "stdafx.h"

namespace IFS_det {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
    using namespace System::Data;
	using namespace System::Drawing;

   
    int iter = 0;
	int choice = 0;
	//тип начального множества(равносторонний треугольник или квадрат)
	int startSetType = 0;
    int save = -1;
	

	public value class PointD
	{ public:
		Double X; Double Y; //System::Double
	};
	
	

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		Double Xmin; Double Xmax; Double Ymin; Double Ymax;
	private: System::Windows::Forms::Button^  butPrint;
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;

	private: System::Windows::Forms::NumericUpDown^  numIters;
	//number of affine transformations
	int numAT;
	//matrix of the affine koeficients
	array<array<Double>^>^ C;
	//matrix of start values
	array<array<Int32>^>^ E0;
	//matrix of result
	array<array<Int32>^>^ T;
	//bitmap which is similar to T
	System::Drawing::Bitmap ^bmp;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ComboBox^  comboBox1;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Xmin = 0; Xmax = 1; Ymin = 0; Ymax = 1;
			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::Panel^  panel1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->butPrint = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numIters = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numIters))->BeginInit();
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(495, 495);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// butPrint
			// 
			this->butPrint->Location = System::Drawing::Point(20, 150);
			this->butPrint->Name = L"butPrint";
			this->butPrint->Size = System::Drawing::Size(71, 19);
			this->butPrint->TabIndex = 2;
			this->butPrint->Text = L"Print!";
			this->butPrint->UseVisualStyleBackColor = true;
			this->butPrint->Click += gcnew System::EventHandler(this, &Form1::butPrint_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Number of iter-s";
			// 
			// numIters
			// 
			this->numIters->Location = System::Drawing::Point(19, 30);
			this->numIters->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->numIters->Name = L"numIters";
			this->numIters->Size = System::Drawing::Size(48, 20);
			this->numIters->TabIndex = 0;
			this->numIters->ValueChanged += gcnew System::EventHandler(this, &Form1::numIters_ValueChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Controls->Add(this->numIters);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->butPrint);
			this->panel2->Location = System::Drawing::Point(502, 24);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(270, 493);
			this->panel2->TabIndex = 2;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Sierpinski triangle(default)", L"Sierpinski carpet", 
				L"Unnamed fern", L"Crystal"});
			this->comboBox1->Location = System::Drawing::Point(19, 68);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(168, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->Text = L"Sierpinski triangle(default)";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripMenuItem1, 
				this->saveToolStripMenuItem, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(95, 6);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->aboutToolStripMenuItem->Text = L"About...";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(772, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"bmp";
			this->saveFileDialog1->Filter = L"BMP images|*.bmp|All files|*.*";
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 516);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"IFS_det";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numIters))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: 
  System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
  { this->Close(); }
  
  System::Void ToScreen(PointD W, Point &S) { 
	  S.X = panel1->Width*(W.X  - Xmin)/(Xmax-Xmin);
      S.Y = panel1->Height*(Ymax - W.Y)/(Ymax-Ymin);
  }

  System::Void ToWorld(Point S, PointD &W) {
		W.X = S.X*(Xmax-Xmin)/panel1->Width + Xmin;
		W.Y = S.Y*(Ymin-Ymax)/panel1->Height + Ymax;
  }

private: System::Void numIters_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			iter = Decimal::ToInt32(numIters->Value);
	     }

private: System::Void butPrint_Click(System::Object^  sender, System::EventArgs^  e) {
		    save = 1;
			this->Refresh();
		 }
//делаем матрицу с нулевыми элементами
private: System::Void fillMtxByZeros(array<array<Int32>^>^ S) {
			 for(int i = 0; i < S->Length; i++)
				 for(int j = 0; j < S->Length; j++)
					 S[i][j] = 0;
		 }

//affine transofrmations for the Sierpinski triangle
private: System::Void applySierTrian() {
				if(iter > 7){
					iter = 7;
					MessageBox::Show("Iterations for this fractal has restraint by " + iter, "Warning");
				}
				numAT = 3;
				C = gcnew array<array<Double>^>(numAT);
				for(int i = 0; i < numAT; i++)
					C[i] = gcnew array<Double>(6);

				for(int i = 0; i < numAT; i++) {
					C[i][0] = C[i][3] = 0.5;
					C[i][1] = C[i][2] = 0.0;
				}
				C[0][4] = C[0][5] = 0.0;
				C[1][4] = 0.5; C[1][5] = 0.0;
				C[2][4] = 0.25; C[2][5] = 0.433;
		 }

//affine transofrmations for the Sierpinski carpet
private: System::Void applySierCarp() {
				if(iter > 5){
					iter = 5;
					MessageBox::Show("Iterations for this fractal has restraint by " + iter, "Warning");
				}
				numAT = 8;
				C = gcnew array<array<Double>^>(numAT);
				for(int i = 0; i < numAT; i++)
					C[i] = gcnew array<Double>(6);
				double koef = 1.0/3.0;
				for(int i = 0; i < numAT; i++) {
					C[i][0] = C[i][3] = koef;
					C[i][1] = C[i][2] = 0.0;
				}
				C[0][4] = C[0][5] = 0.0;
				C[1][4] = 0.0; C[1][5] = koef;
				C[2][4] = 0.0; C[2][5] = 2*koef;

				C[3][4] = koef; C[3][5] = 0.0;
				C[4][4] = koef; C[4][5] = 2*koef;

				C[5][4] = 2*koef; C[5][5] = 0.0;
				C[6][4] = 2*koef; C[6][5] = koef;
				C[7][4] = 2*koef; C[7][5] = 2*koef;
		 }

//affine transofrmations for the unnamed fern
private: System::Void applyUnFern() {
				if(iter > 15){
					iter = 15;
					MessageBox::Show("Iterations for this fractal has restraint by " + iter, "Warning");
				}
				numAT = 4;
				C = gcnew array<array<Double>^>(numAT);
				for(int i = 0; i < numAT; i++)
					C[i] = gcnew array<Double>(6);
				
				C[0][0] = 0.7; C[0][1] = C[0][2] = 0.0;
				C[0][3] = 0.7; C[0][4] = 0.1496; C[0][5] = 0.2962;
				
				C[1][0] = 0.1; C[1][1] = -0.433; C[1][2] = 0.1732;
				C[1][3] = 0.25; C[1][4] = 0.4478; C[1][5] = 0.0014;
				
				C[2][0] = 0.1; C[2][1] = 0.4333; C[2][2] = -0.1732;
				C[2][3] = 0.25; C[2][4] = 0.4445; C[2][5] = 0.1559;

				C[3][0] = C[3][1] = C[3][2] = 0.0;
				C[3][3] = 0.3; C[3][4] = 0.4987; C[3][5] = 0.007;
		 }

//affine transofrmations for the Crystal
private: System::Void applyCrystal() {
				if(iter > 14){
					iter = 14;
					MessageBox::Show("Iterations for this fractal has restraint by " + iter, "Warning");
				}
				numAT = 4;
				C = gcnew array<array<Double>^>(numAT);
				for(int i = 0; i < numAT; i++)
					C[i] = gcnew array<Double>(6);
				
				C[0][0] = 0.255; C[0][1] = C[0][2] = 0.0;
				C[0][3] = 0.255; C[0][4] = 0.3726; C[0][5] = 0.6714;
				
				C[1][0] = 0.255; C[1][1] = C[0][2] = 0.0;
				C[1][3] = 0.255; C[1][4] = 0.1146; C[1][5] = 0.2232;

				C[2][0] = 0.255; C[2][1] = C[2][2] = 0.0;
				C[2][3] = 0.255; C[2][4] = 0.6306; C[2][5] = 0.2232;

				C[3][0] = 0.37; C[3][1] = -0.642; C[3][2] = 0.642;
				C[3][3] = 0.37; C[3][4] = 0.6356; C[3][5] = -0.0061;
		 }
//применяем соответствующий метод для задания матрицы коэффицентов С в зависимости от выбора фрактала
private: System::Void setAffineTransforms() {
			 switch(choice) {
				case 0: applySierTrian(); break;
				case 1: applySierCarp(); break;
				case 2: applyUnFern(); break;
				case 3: applyCrystal(); break;
				}
		  }
//устанавливаем начальное множество У0 - треугольник или квадрат
private: System::Void getStartMatrix() {
			//height of panel1(it must be square!)
			int size = panel1->Height;
			E0 = gcnew array<array<Int32>^>(size);
			for(int i = 0; i < size; i++)
				E0[i] = gcnew array<Int32>(size);
			
			fillMtxByZeros(E0);
			
			//E0 contains an equilateral triangle
			if(startSetType == 0) {
				int numLines = size*0.86602540378;
				double tan30 = 0.57735026919;
				for(int i = size-1; i > size-1-numLines; i--)
					for(int j = (size-i-1)*tan30; j < size-(size-i-1)*tan30; j++)  
						E0[i][j] = 1; 
			}else if(startSetType == 1) { //E0 is square as panel1
				for(int i = 0; i < size; i++)
					for(int j = 0; j < size; j++)
						E0[i][j] = 1; 
			}
		}
			
//создаем матрицу Т, получающуюся с пом. детерм. алгоритма СИФ
private: System::Void applyIFS() {
			//create matrix of affine transforms
			setAffineTransforms();
			 //create E0
			getStartMatrix();
			T = E0;

			//create matrix of zeros
			int sz = E0->Length;
			array<array<Int32>^>^ S;
			S = gcnew array<array<Int32>^>(sz);
			for(int i = 0; i < sz; i++)
				S[i] = gcnew array<Int32>(sz);
			fillMtxByZeros(S);

			Point S1, S2;
			PointD W1, W2;
			int ii, jj;

			for(int k = 0; k < iter; k++) {
				for(int i = 0; i < T->Length; i++) {
					for(int j = 0; j < T[i]->Length; j++) {
						if(T[i][j] == 1) {  //it's OK
							//to use affine transofrms we must work in the world coordinates
							//note that the first index of matrix is Y
							S1.X = j; S1.Y = i;
							ToWorld(S1, W1);
							
							for(int l = 0; l < numAT; l++) {
								W2.X = C[l][0]*W1.X + C[l][1]*W1.Y + C[l][4];
								
								if(W2.X <= Xmax && W2.X >= Xmin) { //it seems that it never happens...
									W2.Y = C[l][2]*W1.X + C[l][3]*W1.Y + C[l][5];
									if(W2.Y <= Ymax && W2.Y >= Ymin){
										//now transform back to the screen coordinates
										ToScreen(W2, S2);
										ii = S2.Y; jj = S2.X;
										S[ii][jj] = 1;  
									}
								}
							}
						}
					}
				}
				T = S;
				
				S = gcnew array<array<Int32>^>(sz);
				for(int i = 0; i < sz; i++)
					S[i] = gcnew array<Int32>(sz);
				fillMtxByZeros(S);
			}
		 }
//рисуем из растра изображение фрактала
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			Graphics ^G = e->Graphics;
	        SolidBrush ^B = gcnew SolidBrush(Color::White);

			G->FillRectangle(B, 0,0, panel1->Width, panel1->Height); //закрашиваем всю панель белым цветом
			
			bmp = gcnew Bitmap(panel1->Width, panel1->Height);
			applyIFS();
			int size = T->Length; 

			for(int i = 0; i < size; i++) 
				for(int j = 0; j < size; j++) 
					if(T[i][j] == 1)
						bmp->SetPixel(j, i, Color::Black); //because the first coodinate is X(second index of matrix) in the screen coordinates
								
			G->DrawImage(bmp, 0, 0); //рисуем из растра
		}

private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show("This program was created by Ivanov Artyom.", "About program");
		 }

private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }

private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(save == 1)
			     saveFileDialog1->ShowDialog();
		 }
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 bmp->Save(saveFileDialog1->FileName);
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 String^ text = comboBox1->Text;
			 if(text->Contains("Sierpinski triangle(default)")){
				startSetType = 0;
				choice = 0;
			 } else if(text->Contains("Sierpinski carpet")){
				startSetType = 1;
				choice = 1;
			 }else if(text->Contains("Unnamed fern")){
				startSetType = 1;
				choice = 2;
			 } else if(text->Contains("Crystal")){
				startSetType = 1;
				choice = 3;
			 }
		 }

};


}


