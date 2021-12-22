#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TF1.h>

void insieme() {
  TGraphErrors* g200 = new TGraphErrors("200micro.txt");
  TGraphErrors* g100 = new TGraphErrors("100micro.txt");
  g200->SetTitle("Corrente di base Ib = -200uA");
  g100->SetTitle("Corrente di base Ib = -100uA");
  g200->GetXaxis()->SetTitle("Tensione tra collettore ed emettitore (|Vce|), V");
  g200->GetYaxis()->SetTitle("Corrente di collettore (|Ic|), mA");

  g200->SetMarkerStyle(20);
  g200->SetMarkerColor(kBlue);
  g200->SetMarkerSize(0.5);
  g100->SetMarkerStyle(20);
  g100->SetMarkerColor(kRed);
  g100->SetMarkerSize(0.5);

  //g200->SetMarkerStyle(4);
  g200->Draw("AP");
  g100->Draw("SAME");
  
  g200->SetLineColor(kBlue);
  g100->SetLineColor(kRed);

  
  TLegend* l = new TLegend();
  l->AddEntry(g200);
  l->AddEntry(g100);
  l->Draw();
  g200->SetTitle("Caratteristica di uscita del BJT");
}

void fit() {
  TGraphErrors* g200 = new TGraphErrors("200micro.txt");
  TGraphErrors* g100 = new TGraphErrors("100micro.txt");
  g200->SetTitle("Corrente di base Ib = -200uA");
  g100->SetTitle("Corrente di base Ib = -100uA");
  g200->GetXaxis()->SetTitle("Tensione tra collettore ed emettitore (|Vce|), V");
  g200->GetYaxis()->SetTitle("Corrente di collettore (|Ic|), mA");
  g100->GetXaxis()->SetTitle("Tensione tra collettore ed emettitore (|Vce|), V");
  g100->GetYaxis()->SetTitle("Corrente di collettore (|Ic|), mA");

  g200->SetMarkerStyle(20);
  g200->SetMarkerColor(kBlue);
  g200->SetMarkerSize(0.5);
  g100->SetMarkerStyle(20);
  g100->SetMarkerColor(kRed);
  g100->SetMarkerSize(0.5);

  TCanvas* c200 = new TCanvas("c200", "Corrente di base Ib = -200uA");
  TCanvas* c100 = new TCanvas("c100", "Corrente di base Ib = -100uA");

  c200->cd(); g200->Draw("AP");
  c100->cd(); g100->Draw("AP");

  TF1* f200 = new TF1("f200","pol1");
  TF1* f100 = new TF1("f100","pol1");
  f200->SetLineColor(kRed);
  f100->SetLineColor(kBlue);

  g200->Fit(f200,"","", 1.5, 5);
  g100->Fit(f100,"","", 1.5, 5);
  gStyle->SetOptFit(1111); 

  /*
  TF1* f200 = new TF1("f200", "[0]*(exp(x/[1])-1.)", 400, 690);

  f1->SetParameter(0, 1e-6);
  f1->SetParameter(1, 50.0);
  f1->SetParName(0, "I0");
  f1->SetParName(1, "Eta*VT");

  g1->Fit("f1", "R");
  */
}