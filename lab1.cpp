#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <TF1.h>
#include <TStyle.h>

void calibration() {

  TGraphErrors* g0 = new TGraphErrors("calibrazione.txt");
  g0->SetTitle("Calibrazione oscilloscopio");
  g0->SetMarkerStyle(4);
  
  TCanvas* c0 = new TCanvas("calibCanvas", "Calibrazione oscilloscopio");
  c0->cd(); g0->Draw("AP");

  g0->Fit("pol1");
  g0->GetXaxis()->SetTitle("Tensione multimetro (V)");
  g0->GetYaxis()->SetTitle("Tensione oscilloscopio (V)");
  gStyle->SetOptFit(1111);
}

void silicio() {
  TGraphErrors* g1 = new TGraphErrors("silicio.txt");
  g1->SetTitle("Diodo al Si");

  g1->SetMarkerStyle(4);
  
  TCanvas* c1 = new TCanvas("silicioCanvas", "Diodo al Si");
  c1->cd(); g1->Draw("AP");
  c1->SetLogy();
  c1->SetGrid();
  g1->GetXaxis()->SetTitle("Voltage (mV)");
  g1->GetYaxis()->SetTitle("Current(mA)");

  TF1* f1 = new TF1("f1", "[0]*(exp(x/[1])-1.)", 400, 690);

  f1->SetParameter(0, 1e-6);
  f1->SetParameter(1, 50.0);
  f1->SetParName(0, "I0");
  f1->SetParName(1, "Eta*VT");

  g1->Fit("f1", "R");
  gStyle->SetOptFit(1111);
}

void germanio() {
  TGraphErrors* g2 = new TGraphErrors("germanio.txt");
  g2->SetTitle("Diodo al Ge");

  g2->SetMarkerStyle(4);
  
  TCanvas* c2 = new TCanvas("germanioCanvas", "Diodo al Ge");
  c2->cd(); g2->Draw("AP");
  c2->SetLogy();
  c2->SetGrid();
  g2->GetXaxis()->SetTitle("Voltage (mV)");
  g2->GetYaxis()->SetTitle("Current(mA)");

  TF1* f2 = new TF1("f2", "[0]*(exp(x/[1])-1.)", 50, 330);

  f2->SetParameter(0, 1e-6);
  f2->SetParameter(1, 50.0);
  f2->SetParName(0, "I0");
  f2->SetParName(1, "Eta*VT");

  g2->Fit("f2", "R");
  gStyle->SetOptFit(1111);
}