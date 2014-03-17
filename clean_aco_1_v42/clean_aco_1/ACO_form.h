#pragma once

#include "test.h"

extern test tt;

#include "harta_gen_form.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace clean_aco_1 {

	/// <summary>
	/// Summary for ACO_form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ACO_form : public System::Windows::Forms::Form
	{
	public:
		ACO_form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ACO_form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::CheckBox^  checkBox1;





	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::CheckBox^  checkBox2;

	protected: 

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(231, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 29);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ACO_1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ACO_form::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(498, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 29);
			this->button2->TabIndex = 1;
			this->button2->Text = L"ACO_2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ACO_form::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(766, 15);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 29);
			this->button3->TabIndex = 2;
			this->button3->Text = L"ACO_3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ACO_form::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(231, 66);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(140, 27);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Reloc ACO_1";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ACO_form::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(498, 66);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(140, 27);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Reloc ACO_2";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ACO_form::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(766, 69);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(140, 27);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Reloc ACO_3";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &ACO_form::button6_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Column1, 
				this->Column5, this->Column2, this->Column3, this->Column4});
			this->dataGridView1->Location = System::Drawing::Point(48, 187);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(858, 381);
			this->dataGridView1->TabIndex = 7;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Tip";
			this->Column1->Name = L"Column1";
			// 
			// Column5
			// 
			this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column5->HeaderText = L"Pasi";
			this->Column5->Name = L"Column5";
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Timp";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"Tinte";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column4->HeaderText = L"Relativ";
			this->Column4->Name = L"Column4";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Maroon;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(810, 596);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(162, 54);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Close";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &ACO_form::button7_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(48, 21);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(96, 20);
			this->checkBox1->TabIndex = 9;
			this->checkBox1->Text = L"show map";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &ACO_form::checkBox1_CheckedChanged);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(48, 114);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(125, 36);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Refresh_rez";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &ACO_form::button8_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox2->Location = System::Drawing::Point(48, 66);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(112, 20);
			this->checkBox2->TabIndex = 11;
			this->checkBox2->Text = L"step by step";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &ACO_form::checkBox2_CheckedChanged);
			// 
			// ACO_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 662);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"ACO_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ACO_form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 tt.alg_aco.run_aco1();		// run aco1
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 tt.alg_aco.run_aco2();		// run aco2
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

				 tt.alg_aco.run_aco3();		// run aco3
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

				 tt.alg_aco.run_reloc_aco1();		// run reloc aco1
	}

	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

				 tt.alg_aco.run_reloc_aco2();		// run reloc aco2
	}

	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

				 tt.alg_aco.run_reloc_aco3();		// run reloc aco3
	}


	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	
	}

	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Hide();
	}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 if(this->checkBox1->Checked){
				 tt.harta_pas = 1;
			 }

			 if(! this->checkBox1->Checked){
				 tt.harta_pas = 0;			
			 }
		 }

private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {

			Rezultat rez = tt.rez_aco.back();

			System::String^ s0 = gcnew System::String(rez.tip.c_str());
			System::String^ s1 = System::Convert::ToString(rez.pasi);
			System::String^ s2 = System::Convert::ToString(rez.timp);
			System::String^ s3 = System::Convert::ToString(rez.tinte);
			System::String^ s4 = System::Convert::ToString(rez.rel);

			this->dataGridView1->Rows->Add(s0, s1, s2, s3, s4);
			//this->dataGridView1->Rows[1]->HeaderCell->Value = "123";
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 if(this->checkBox2->Checked){
				 tt.pas_cu_pas = 1;
			 }

			 if(! this->checkBox2->Checked){
				 tt.pas_cu_pas = 0;
			 }
		 }
};
}
