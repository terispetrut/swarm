#pragma once

#include "test.h"

extern test tt;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace clean_aco_1 {

	/// <summary>
	/// Summary for harta_gen_form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class harta_gen_form : public System::Windows::Forms::Form
	{
	public:
		harta_gen_form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		harta_gen_form(int nr)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~harta_gen_form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: int **mem;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;


	//protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(91, 43);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(539, 231);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Maroon;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(617, 294);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &harta_gen_form::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(12, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Next";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &harta_gen_form::button2_Click);
			// 
			// harta_gen_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(719, 341);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"harta_gen_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"harta_gen_form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Hide();
	}

	//=========================================================================

	public: System::Void reset_map(){
			
				for(int i = 0; i < tt.nr_ll; i++){

					for(int j = 0; j < tt.nr_cc; j++){

						if(tt.map[i][j] == 0){			// spatiu liber
							this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
								System::Drawing::Color::Aqua;
						}

						if(tt.map[i][j] == 1){			// obstacol
							this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
								System::Drawing::Color::Brown;
						}

						if(tt.map[i][j] == 2){			// tinta
							this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
								System::Drawing::Color::Green;
						}
					}
				}
			}

	//=========================================================================

	public: System::Void reset_this_map(int **mm){
			
				for(int i = 0; i < tt.nr_ll; i++){

					for(int j = 0; j < tt.nr_cc; j++){

						if(this->mem[i][j] != mm[i][j]){

							this->mem[i][j] = mm[i][j];

							if(mm[i][j] == 0){			// spatiu liber
								this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
									System::Drawing::Color::Aquamarine;
							}

							if(mm[i][j] == 1){			// obstacol
								this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
									System::Drawing::Color::Brown;
							}

							if(mm[i][j] == 2){			// tinta
								this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
									System::Drawing::Color::Green;
							}

							if(mm[i][j] == 3){			// tinta
								this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
									System::Drawing::Color::Orange;
							}
						}
					}
				}
			}

	// ========================================================================

	public: System::Void color_map_init(){

				int cw, ch;

				this->mem = new int *[tt.nr_ll];

				for(int i = 0; i < tt.nr_ll; i++){
					this->mem[i] = new int [tt.nr_cc];
				}

				for(int i = 0; i < tt.nr_ll; i++){
					for(int j = 0; j < tt.nr_cc; j++){
						this->mem[i][j] = -1;
					}
				}

				this->Size = System::Drawing::Size(1200, 750);
	
				this->dataGridView1->Size = System::Drawing::Size(1115, 605);
				this->dataGridView1->ColumnCount = tt.nr_cc;
				this->dataGridView1->RowCount = tt.nr_ll;
				this->dataGridView1->ColumnHeadersVisible = false;
				this->dataGridView1->RowHeadersVisible = false;
				this->dataGridView1->Location = System::Drawing::Point(30, 40);
				this->button1->Location = System::Drawing::Point(1070, 650);
				this->button2->Location = System::Drawing::Point(30, 12);

				this->dataGridView1->ReadOnly = true;
				
								
				cw = (int)(1100 / tt.nr_cc);
				ch = (int)(600 / tt.nr_ll);

				for(int i = 0; i < tt.nr_cc; i++){
					this->dataGridView1->Columns[i]->Width = cw;
				}

				for(int i = 0; i < tt.nr_ll; i++){
					this->dataGridView1->Rows[i]->Height = ch;
				}

			}

	//=========================================================================

	public: System::Void color_map(){				// ??????????
			
				int cw, ch;

				this->Size = System::Drawing::Size(1200, 750);
	
				this->dataGridView1->Size = System::Drawing::Size(1105, 605);
				this->dataGridView1->ColumnCount = tt.nr_cc;
				this->dataGridView1->RowCount = tt.nr_ll;
				this->dataGridView1->ColumnHeadersVisible = false;
				this->dataGridView1->RowHeadersVisible = false;
				this->dataGridView1->Location = System::Drawing::Point(30, 30);
				this->button1->Location = System::Drawing::Point(1000, 650);

				this->dataGridView1->ReadOnly = true;
				
								
				cw = (int)(1100 / tt.nr_cc);
				ch = (int)(600 / tt.nr_ll);

				for(int i = 0; i < tt.nr_cc; i++){
					this->dataGridView1->Columns[i]->Width = cw;
				}

				for(int i = 0; i < tt.nr_ll; i++){
					this->dataGridView1->Rows[i]->Height = ch;
				}

				for(int i = 0; i < tt.nr_ll; i++){

					for(int j = 0; j < tt.nr_cc; j++){

						if(tt.map[i][j] == 0){			// spatiu liber
							this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
								System::Drawing::Color::Aqua;
						}

						if(tt.map[i][j] == 1){			// obstacol
							this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
								System::Drawing::Color::Brown;
						}

						if(tt.map[i][j] == 2){			// tinta
							this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = 
								System::Drawing::Color::Green;
						}
					}
				}
			}

	//=========================================================================

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

			 //this->reset_this_map(tt.ob_aco1.map);

			 tt.next_pas = 1;
		 }
};
}
