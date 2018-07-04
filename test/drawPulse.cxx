void drawPulse(std::string name_input_file = "out.root", int ix_todraw = 10, int iy_todraw = 10, int iz_todraw = 10){
  
  Color_t* color = new Color_t [200];
  color[0] = kAzure; //kRed ;
  color[1] = kAzure + 10 ;
  color[2] = kYellow + 2 ;
  color[3] = kGreen ;
  color[4] = kGreen + 4 ;
  color[5] = kBlue ;
  color[6] = kCyan ;
  color[7] = kPink + 1 ;
  color[8] = kBlack ;
  color[9] = kYellow + 4 ;
  for (int i=0; i<30; i++) {
    color[i+10] = kBlue + i;
  }
  
  
  TFile* inputFile = new TFile (name_input_file.c_str(), "READ");  
  
  TTree* outputTree = (TTree*) inputFile -> Get ("outputTree");
  
  gStyle->SetOptStat(0);
  
  
  std::cout << " ix_todraw = " << ix_todraw << std::endl;
  std::cout << " iy_todraw = " << iy_todraw << std::endl;
  std::cout << " iz_todraw = " << iz_todraw << std::endl;
  
  
   
  //
  // ---- read iring definition from file
  //        (ix, iy, iz) -> ring
  //
  
  
  std::map < std::pair<int, int> , int > iring_map_plus;
  std::map < std::pair<int, int> , int > iring_map_minus;
  
  std::ifstream fileEEring ("test/eerings.dat"); 
  
  std::string buffer;
  int num;
  if (!fileEEring.is_open()) {
    std::cerr << "** ERROR: Can't open for input" << std::endl;
    return false;
  }
  
  while(!fileEEring.eof()) {
    getline(fileEEring,buffer);
    if (buffer != ""){ ///---> save from empty line at the end!
      int ix;
      int iy;
      int iz;
      int iring;
      
      //       std::cout << " buffer = " << buffer << std::endl;
      
      std::stringstream line( buffer );      
      line >> ix; 
      line >> iy; 
      line >> iz; 
      line >> iring; 
      
      std::pair<int, int> ixiy (ix, iy);
      //       if (iz>0) iring_map_plus  [ixiy] = 38 - iring;
      //       else      iring_map_minus [ixiy] = 38 - iring;
      
      if (iz>0) iring_map_plus  [ixiy] = iring;
      else      iring_map_minus [ixiy] = iring;
      
    } 
  }
  
  
  
  
  
  
  
  
  
  std::vector<int> ix_ieta;
  std::vector<int> iy_iphi;
  std::vector<int> v_iz;
  
  std::vector<float> v_bias;
  
  
  
  float bias;
  float EbxM1; //---- energy in BX -1
  int ieta;
  int iphi;
  int iz;
  
  std::vector <float>* samplesReco        = new std::vector <float> ; //---- the reconstructed energy per BX
  std::vector <float>* samplesSim         = new std::vector <float> ; //---- the simulated pulse
  std::vector <float>* pulseShapeTemplate = new std::vector <float> ; //---- the pulse shape template
  
    
  outputTree->SetBranchAddress("bias",  &bias);
  outputTree->SetBranchAddress("EbxM1", &EbxM1);
  outputTree->SetBranchAddress("ieta",  &ieta);
  outputTree->SetBranchAddress("iphi",  &iphi);
  outputTree->SetBranchAddress("iz",    &iz);
  outputTree->SetBranchAddress("samplesReco",  &samplesReco);
  outputTree->SetBranchAddress("samplesSim",  &samplesSim);
  outputTree->SetBranchAddress("pulseShapeTemplate",  &pulseShapeTemplate);
  
  TCanvas* cc_pulse = new TCanvas ("cc_pulse", "pulse", 800,600);

  TGraph *grReco = new TGraph();
  TGraph *grPulse = new TGraph();
  TGraph *grPulseRecoAll = new TGraph();
  TGraph *grPulseReco[10];
  
  std::cout << " outputTree->GetEntries() = " << outputTree->GetEntries() << std::endl;
  
  TLegend* leg = new TLegend(0.91,0.10,0.99,0.90);
  
  
  for (int iEntry=0; iEntry<outputTree->GetEntries(); iEntry++) {
    
    outputTree->GetEntry(iEntry);
    
    if ( (ieta == ix_todraw) && (iphi == iy_todraw) &&  (iz == iz_todraw) ) {
   
      for(int i=0; i<samplesReco->size(); i++){
        grReco->SetPoint(i, i, samplesReco->at(i));
      }
      grReco->SetMarkerSize(2);
      grReco->SetMarkerStyle(22);
      grReco->SetMarkerColor(kBlue);
      grReco->Draw("ALP");
      grReco->GetXaxis()->SetTitle("BX");
      
  
      for(int i=0; i<samplesSim->size(); i++){
        grPulse->SetPoint(i, i , 1000.* samplesSim->at(i));
      }
      grPulse->SetMarkerSize(2);
      grPulse->SetMarkerStyle(21);
      grPulse->SetMarkerColor(kRed);
      grPulse->SetLineStyle(3);
      grPulse->SetLineColor(kRed);
      grPulse->SetLineWidth(2);
      grPulse->Draw("LP");

      
      std::vector<float> totalRecoSpectrum;
      for(int i=0; i<samplesSim->size(); i++){
        totalRecoSpectrum.push_back(0);
      }
      
      
      
      for(int iBx=0; iBx<samplesReco->size(); iBx++){
        grPulseReco[iBx] = new TGraph();
        for(int i=0; i<samplesSim->size(); i++){
          grPulseReco[iBx]->SetPoint(i, i + iBx - 2 , pulseShapeTemplate->at(i+7) * samplesReco->at(iBx));
          // FIXME: why - 2 ?
          // FIXME: why + 7 ? I added + 7 in the CondDBDumper.h
          
          int iReco = (i + iBx - 2);
          if ( iReco >= 0 && iReco <samplesSim->size() ) {
            totalRecoSpectrum.at(iReco) += pulseShapeTemplate->at(i+7) * samplesReco->at(iBx);
          } 
          
        }
        
        grPulseReco[iBx]->SetMarkerColor(color[iBx]);
        grPulseReco[iBx]->SetLineColor(color[iBx]);
        grPulseReco[iBx]->SetMarkerSize(1);
        grPulseReco[iBx]->SetMarkerStyle(21+iBx);
        TString nameHistoTitle = Form ("BX %d", iBx);
        leg->AddEntry(grPulseReco[iBx],nameHistoTitle.Data(),"p");
        grPulseReco[iBx]->Draw("PL");
      }
      
      
      
      for(int i=0; i<samplesSim->size(); i++){
        grPulseRecoAll->SetPoint(i, i, totalRecoSpectrum.at(i));
      }
      
      grPulseRecoAll->SetMarkerColor(kMagenta);
      grPulseRecoAll->SetLineColor(kMagenta);
      grPulseRecoAll->SetLineStyle(1);
      grPulseRecoAll->SetMarkerSize(3);
      grPulseRecoAll->SetMarkerStyle(24);
      grPulseRecoAll->Draw("PL");
      
      
      leg->Draw();
      
    }
    
    
    ix_ieta.push_back(ieta);
    iy_iphi.push_back(iphi);
    v_iz.push_back(iz);
    
    v_bias.push_back(bias);
    
    
  }
  
  
  std::cout << " ix_ieta.size() = " << ix_ieta.size() << std::endl;
  
  if (ix_ieta.size() > 75848) {
    std::cout << " Attention: wrong number of crystals?? ix_ieta.size() = " << ix_ieta.size() << std::endl;
  }    
  
  
  //---- EB ----
  TCanvas* ccEB = new TCanvas ("ccEB","",1600,600);
  ccEB->cd();
  
  TH2F* histoEB_v_bias = new TH2F ("histoEB_v_bias", "G12 bias" ,  360, 0.5, 360.5,  171, -85.5, 85.5);
   
  
  histoEB_v_bias->GetXaxis()->SetTitle("i#phi");
  histoEB_v_bias->GetYaxis()->SetTitle("i#eta");
  
  for (int iter = 0; iter < ix_ieta.size(); iter++) {
    if (v_iz.at(iter) == 0) {
      
      histoEB_v_bias->Fill(iy_iphi.at(iter), ix_ieta.at(iter), v_bias.at(iter) );
      
    }
  }
  
  
  histoEB_v_bias->Draw("colz");
  histoEB_v_bias->GetZaxis()->SetRangeUser( 0.99, 1.01 );
  
  ccEB->SaveAs("biasEB.png");
  ccEB->SaveAs("biasEB.root");
  
  
  
  
  
  TCanvas* ccEB_unzoom = new TCanvas ("ccEB_unzoom","",1600,600);
  
  histoEB_v_bias->Draw("colz");
  histoEB_v_bias->GetZaxis()->SetRangeUser( 0.90, 1.10 );
  
  ccEB_unzoom->SaveAs("biasEB_unzoom.png");
  ccEB_unzoom->SaveAs("biasEB_unzoom.root");
  
  
  
  TCanvas* ccEB_zoom = new TCanvas ("ccEB_zoom","",1600,600);
  
  histoEB_v_bias->Draw("colz");
  histoEB_v_bias->GetZaxis()->SetRangeUser( 0.995, 1.005 );
  
  ccEB_zoom->SaveAs("biasEB_zoom.png");
  ccEB_zoom->SaveAs("biasEB_zoom.root");
  
  
  
  
  
  //---- EE ----
  TCanvas* ccEE = new TCanvas ("ccEE","",1600,600);
  ccEE->cd();
  
  TH2F* histoEE_v_bias = new TH2F ("histoEE_v_bias", "G12 bias" ,  200, 0.5, 200.5,  100, 0.5, 100.5);
  
  histoEE_v_bias->GetXaxis()->SetTitle("x");
  histoEE_v_bias->GetYaxis()->SetTitle("y");
  
  
  for (int iter = 0; iter < ix_ieta.size(); iter++) {
    if (v_iz.at(iter) != 0) {
      
      histoEE_v_bias->Fill(ix_ieta.at(iter) + 100*(v_iz.at(iter)>0), iy_iphi.at(iter), v_bias.at(iter) );
      
    }
  }
  
  histoEE_v_bias->Draw("colz");
  histoEE_v_bias->GetZaxis()->SetRangeUser( 0.9, 1.1 );
  
  ccEE->SaveAs("biasEE.png");
  ccEE->SaveAs("biasEE.root");
  
 
  TCanvas* ccEE_unzoom = new TCanvas ("ccEE_unzoom","",1600,600);
  
  histoEE_v_bias->Draw("colz");
  histoEE_v_bias->GetZaxis()->SetRangeUser( 0.80, 1.20 );
  
  ccEE_unzoom->SaveAs("biasEE_unzoom.png");
  ccEE_unzoom->SaveAs("biasEE_unzoom.root");

  
  
  TCanvas* ccEE_zoom = new TCanvas ("ccEE_zoom","",1600,600);
  
  histoEE_v_bias->Draw("colz");
  histoEE_v_bias->GetZaxis()->SetRangeUser( 0.99, 1.01 );
  
  ccEE_zoom->SaveAs("biasEE_zoom.png");
  ccEE_zoom->SaveAs("biasEE_zoom.root");
  
  
  
  //   
  //   iring = sqrt ((ix-100)^2 + (iy-100)^2)
  //   
  
  std::vector<float> ringPlus_v_bias;          std::vector<float> ringMinus_v_bias;
  
  std::vector<int> ringPlus_count;          std::vector<int> ringMinus_count;  
 
  
  for (int iter = 0; iter < (50-11+3); iter++) {
    ringPlus_v_bias.push_back(0);            ringMinus_v_bias.push_back(0);
    ringPlus_count.push_back(0);            ringMinus_count.push_back(0);
  }
  
  for (int iter = 0; iter < ix_ieta.size(); iter++) {
    if (v_iz.at(iter) != 0) {
      
      int iring = -99;
      std::pair<int, int> ixiy (ix_ieta.at(iter), iy_iphi.at(iter));   
      
      if (v_iz.at(iter) > 0) {
        iring = iring_map_plus [ixiy];
      }
      else {
        iring = iring_map_minus [ixiy];        
      }
      
           
//       float dx = ix_ieta.at(iter) - 50;
//       float dy = iy_iphi.at(iter) - 50;
//       
//       float ring = sqrt( dx*dx + dy*dy );
//       
//       int iring = round(ring) - 11;  //---- 12 [ = (62 - 50 - 1) from the 2D plot] is the first ring
//       
//       
//       if (iring > (50-11+2) || iring < 0) std::cout << " what ?!?   iring = " << iring << " dx = " << dx << " dy = " << dy << " :::: ix = " << ix_ieta.at(iter) << "  iy = " << iy_iphi.at(iter) << std::endl;
      
      if (v_iz.at(iter) > 0) {
        
        ringPlus_v_bias.at(iring) = ringPlus_v_bias.at(iring) + v_bias.at(iter);
        ringPlus_count.at(iring) =  ringPlus_count.at(iring) + 1 ;      
        
      } 
      else {
        
        ringMinus_v_bias.at(iring) = ringMinus_v_bias.at(iring) + v_bias.at(iter);
        ringMinus_count.at(iring) =  ringMinus_count.at(iring) + 1 ;      
      }
      
    } 
  }
  
  
  TGraph *gr_EEPlus_v_bias = new TGraph();     TGraph *gr_EEMinus_v_bias = new TGraph();
  
  for (int iter = 0; iter < (39); iter++) {
//   for (int iter = 0; iter < (50-11+3); iter++) {
    
    
//     gr_EEPlus_v_bias-> SetPoint (iter,  42 -  iter,   ringPlus_count.at(iter) ? ringPlus_v_bias.at(iter) / ringPlus_count.at(iter) : 0 ) ;               
//     gr_EEMinus_v_bias-> SetPoint (iter, 42 -   iter,   ringMinus_count.at(iter) ?  ringMinus_v_bias.at(iter) / ringMinus_count.at(iter) : 0 ) ;  
//     
//     gr_EEPlus_v_bias-> SetPoint (iter,  42 -  iter,   ringPlus_count.at(iter) ? ringPlus_v_bias.at(iter) / ringPlus_count.at(iter) : 0 ) ;               
//     gr_EEMinus_v_bias-> SetPoint (iter, 42 -   iter,   ringMinus_count.at(iter) ?  ringMinus_v_bias.at(iter) / ringMinus_count.at(iter) : 0 ) ;  
    

    gr_EEPlus_v_bias-> SetPoint (iter,  iter +1,   ringPlus_count.at(iter) ? ringPlus_v_bias.at(iter) / ringPlus_count.at(iter) : 0 ) ;               
    gr_EEMinus_v_bias-> SetPoint (iter, iter +1,   ringMinus_count.at(iter) ?  ringMinus_v_bias.at(iter) / ringMinus_count.at(iter) : 0 ) ;  
    
    gr_EEPlus_v_bias-> SetPoint (iter,  iter +1,   ringPlus_count.at(iter) ? ringPlus_v_bias.at(iter) / ringPlus_count.at(iter) : 0 ) ;               
    gr_EEMinus_v_bias-> SetPoint (iter, iter +1,   ringMinus_count.at(iter) ?  ringMinus_v_bias.at(iter) / ringMinus_count.at(iter) : 0 ) ;  
    
    
  }
  
  
  //---- style ----
  
  gr_EEPlus_v_bias->SetMarkerSize  (1);                           gr_EEMinus_v_bias->SetMarkerSize  (1);
  gr_EEPlus_v_bias->SetMarkerStyle (24);                          gr_EEMinus_v_bias->SetMarkerStyle (22);
  gr_EEPlus_v_bias->SetMarkerColor (kRed);                        gr_EEMinus_v_bias->SetMarkerColor (kRed);
  gr_EEPlus_v_bias->SetLineWidth (1);                             gr_EEMinus_v_bias->SetLineWidth (1);
  gr_EEPlus_v_bias->SetLineColor (kRed);                          gr_EEMinus_v_bias->SetLineColor (kRed);
  
  
  //---- style (end) ----
  
  TLegend* leg_EE = new TLegend(0.20,0.20,0.50,0.40);
  leg_EE->AddEntry(gr_EEPlus_v_bias, "EE+","pl");
  leg_EE->AddEntry(gr_EEMinus_v_bias,"EE-","pl");
  
  
  TCanvas* ccRing = new TCanvas ("ccRing","",800,600);
  
  gr_EEPlus_v_bias->Draw("APL");
  gr_EEMinus_v_bias->Draw("PL");
  
  gr_EEPlus_v_bias->GetYaxis()->SetTitle("bias");
  gr_EEPlus_v_bias->GetXaxis()->SetTitle("iRing");
  
  leg_EE->Draw();
  
  ccRing->SaveAs("biasVsRing_EE.png");
  ccRing->SaveAs("biasVsRing_EE.root");
  
  
  
  
  //   
  //   iring = ieta in EB
  //   
  
  std::vector<float> EBringPlus_v_bias;          std::vector<float> EBringMinus_v_bias;
  std::vector<int> EBringPlus_count;          std::vector<int> EBringMinus_count;  
  
  
  for (int iter = 0; iter < 85; iter++) {
    EBringPlus_v_bias.push_back(0);            EBringMinus_v_bias.push_back(0);
    EBringPlus_count.push_back(0);            EBringMinus_count.push_back(0);
  }
  
  for (int iter = 0; iter < ix_ieta.size(); iter++) {
    if (v_iz.at(iter) == 0) {
      
      int iEBring = abs(ix_ieta.at(iter)) - 1 ;
      
      
      if (iEBring > 84 || iEBring < 0) std::cout << " what ?!?   iEBring = " << iEBring << std::endl;
      
      if (ix_ieta.at(iter) > 0) {
        
        EBringPlus_v_bias.at(iEBring) = EBringPlus_v_bias.at(iEBring) + v_bias.at(iter);
        EBringPlus_count.at(iEBring) =  EBringPlus_count.at(iEBring) + 1 ;      
        
      } 
      else {
        
        EBringMinus_v_bias.at(iEBring) = EBringMinus_v_bias.at(iEBring) + v_bias.at(iter);
        EBringMinus_count.at(iEBring) =  EBringMinus_count.at(iEBring) + 1 ;      
      }
      
    } 
  }
  
  
  TGraph *gr_EBPlus_v_bias = new TGraph();     TGraph *gr_EBMinus_v_bias = new TGraph();
  
  for (int iter = 0; iter < 85; iter++) {
    
    
    gr_EBPlus_v_bias-> SetPoint (iter,    iter+1,   EBringPlus_count.at(iter) ? EBringPlus_v_bias.at(iter) / EBringPlus_count.at(iter) : 0 ) ;           
    gr_EBMinus_v_bias-> SetPoint (iter,    iter+1,   EBringMinus_count.at(iter) ?  EBringMinus_v_bias.at(iter) / EBringMinus_count.at(iter) : 0 ) ;  
    
  }
  
  
  //---- style ----
  
  gr_EBPlus_v_bias->SetMarkerSize  (1);                           gr_EBMinus_v_bias->SetMarkerSize  (1);
  gr_EBPlus_v_bias->SetMarkerStyle (24);                          gr_EBMinus_v_bias->SetMarkerStyle (22);
  gr_EBPlus_v_bias->SetMarkerColor (kRed);                        gr_EBMinus_v_bias->SetMarkerColor (kRed);
  gr_EBPlus_v_bias->SetLineWidth (1);                             gr_EBMinus_v_bias->SetLineWidth (1);
  gr_EBPlus_v_bias->SetLineColor (kRed);                          gr_EBMinus_v_bias->SetLineColor (kRed);
  
  
  //---- style (end) ----
  
  TLegend* leg_EB = new TLegend(0.20,0.70,0.50,0.90);
  leg_EB->AddEntry(gr_EBPlus_v_bias, "EB+","pl");
  leg_EB->AddEntry(gr_EBMinus_v_bias,"EB-","pl");
  
  
  
  
  TCanvas* ccRingEB = new TCanvas ("ccRingEB","",800,600);
  
  gr_EBPlus_v_bias->Draw("APL");
  gr_EBMinus_v_bias->Draw("PL");
  
  gr_EBPlus_v_bias->GetYaxis()->SetTitle("bias");
  gr_EBPlus_v_bias->GetXaxis()->SetTitle("i#eta");
  
  leg_EB->Draw();
  
  ccRingEB->SaveAs("biasVsRing_EB.png");
  ccRingEB->SaveAs("biasVsRing_EB.root");
  
  
 

}

