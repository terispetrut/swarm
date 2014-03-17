#pragma once

#include "test.h"

extern test tt;

//#include <iostream>
//#include <string>
//#include <msclr\marshal_cppstd.h>

using namespace std;
//using namespace msclr::interop;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace clean_aco_1 {


	/// <summary>
	/// Summary for generare_form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class generare_form : public System::Windows::Forms::Form
	{
	public:
		generare_form(void)
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
		~generare_form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(47, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Time (sec)";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &generare_form::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(153, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(153, 89);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(153, 118);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(565, 37);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox4->Size = System::Drawing::Size(190, 90);
			this->textBox4->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(562, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Notificari";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(47, 238);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 37);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Load from file";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &generare_form::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(251, 238);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(202, 37);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Random";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &generare_form::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(553, 238);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(202, 37);
			this->button4->TabIndex = 10;
			this->button4->Text = L"DFS";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &generare_form::button4_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(412, 37);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(103, 20);
			this->textBox5->TabIndex = 12;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Maroon;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(651, 370);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 46);
			this->button5->TabIndex = 13;
			this->button5->Text = L"Close";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &generare_form::button5_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(47, 46);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(100, 23);
			this->button7->TabIndex = 15;
			this->button7->Text = L"Nr agents";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &generare_form::button7_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(153, 49);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 16;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(47, 86);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(100, 23);
			this->button8->TabIndex = 17;
			this->button8->Text = L"Nr lines";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &generare_form::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(47, 115);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(100, 23);
			this->button9->TabIndex = 18;
			this->button9->Text = L"Nr columns";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &generare_form::button9_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(313, 35);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(84, 23);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Nr obstacles:";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &generare_form::button6_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(47, 176);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(149, 23);
			this->button10->TabIndex = 20;
			this->button10->Text = L"Nume harta save";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &generare_form::button10_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(232, 179);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(165, 20);
			this->textBox7->TabIndex = 21;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(313, 64);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(84, 21);
			this->button11->TabIndex = 22;
			this->button11->Text = L"Nr targets";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &generare_form::button11_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(412, 64);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(103, 20);
			this->textBox8->TabIndex = 23;
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(47, 385);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(160, 52);
			this->button12->TabIndex = 24;
			this->button12->Text = L"Preview MAP";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &generare_form::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(313, 101);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(84, 23);
			this->button13->TabIndex = 25;
			this->button13->Text = L"Nr clusters";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &generare_form::button13_Click);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(412, 101);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(103, 20);
			this->textBox9->TabIndex = 26;
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(251, 309);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(202, 37);
			this->button14->TabIndex = 27;
			this->button14->Text = L"Random cluster";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &generare_form::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(553, 309);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(202, 37);
			this->button15->TabIndex = 28;
			this->button15->Text = L"DFS cluster";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// generare_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(781, 459);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"generare_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"generare_form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Hide();
	}
	
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		this->openFileDialog1->ShowDialog();
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			if(! String::IsNullOrEmpty(this->textBox1->Text)){
				tt.timp = int::Parse(this->textBox1->Text);
			}
			this->textBox4->AppendText("\r\n> Timp rulare = " + tt.timp);
	}

	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(! String::IsNullOrEmpty(this->textBox6->Text)){
				tt.nr_agenti = int::Parse(this->textBox6->Text);
			 }

			 this->textBox4->AppendText("\r\n> Nr agenti = " + tt.nr_agenti);
	}

	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(! String::IsNullOrEmpty(this->textBox2->Text)){
				tt.nr_ll = int::Parse(this->textBox2->Text);
			 }

			 this->textBox4->AppendText("\r\n> Nr linii = " + tt.nr_ll);
	}

	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(! String::IsNullOrEmpty(this->textBox3->Text)){
				tt.nr_cc = int::Parse(this->textBox3->Text);
			 }

			 this->textBox4->AppendText("\r\n> Nr coloane = " + tt.nr_cc);
	}

	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

			if(! String::IsNullOrEmpty(this->textBox5->Text)){
				tt.nr_obst = int::Parse(this->textBox5->Text);
			}

			this->textBox4->AppendText("\r\n> Nr obstacole = " + tt.nr_obst);
	}

	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(! String::IsNullOrEmpty(this->textBox7->Text)){
				 tt.nume_loc = msclr::interop::marshal_as <std::string> (this->textBox7->Text);
			 }

			 this->textBox4->AppendText("\r\n> Nume harta = " + 
			 	 gcnew String(tt.nume_loc.c_str()));
	}

	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {

			if(! String::IsNullOrEmpty(this->textBox8->Text)){
				tt.nr_tinte = int::Parse(this->textBox8->Text);
			}

			this->textBox4->AppendText("\r\n> Nr tinte = " + tt.nr_tinte);
	}

	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {

			 tt.show_harta_gen_form();
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

			 tt.aloc_map();
			 tt.gen_random_map();
			 tt.afis_map_1();
	}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

			 tt.aloc_map();
			 tt.gen_dfs_map();
			 tt.afis_map_1();
		 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {

			if(! String::IsNullOrEmpty(this->textBox9->Text)){
				 tt.nr_clusters = int::Parse(this->textBox9->Text);
			}

			 this->textBox4->AppendText("\r\n> Nr clusters = " + tt.nr_clusters);
		 }
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {

			 tt.aloc_map();
			 tt.gen_cluster_random();
			 tt.afis_map_1();
		 }
};
}
