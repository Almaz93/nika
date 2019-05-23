{
  Double_t edep=0,impPar=0;
  Double_t edepMod[110]; 
  Double_t edep_12_23;

TFile *_file0 = TFile::Open("c:/root/roothome/nica/bmn/analzdc_CC4GeVmb_1_2.r12_Zpos_8759mm_Xshift_422mm_Yshift_14mm_100000ev.root");

TH1F *hImpPar_nt = new TH1F("hImpPar_nt","hImpPar_nt",2000,0.,20.);

 TTree *pTree=(TTree*)_file0->Get("bigtree_en");
    gdTEvents=pTree->GetEntries();
    cout <<"loop 1 -> gdTEvents " <<gdTEvents <<endl;

    bigtree_en->SetBranchAddress("impPar",&impPar);
    bigtree_en->SetBranchAddress("edep",&edep);//deposited energy in ZDC
    bigtree_en->SetBranchAddress("edepMod",&edepMod);//deposited energy in modules [0 - 103]

    for(Int_t iEventN=0;iEventN<gdTEvents;iEventN++){// loop on events
      bigtree_en->GetEntry(iEventN);

      hImpPar_nt->Fill(impPar);	  
      //hEdep_nt->Fill(edep);//Edep	  
      //hEdep_nt->Fill(edep*70./2.5);//Edep->Erec	  

      edep_12_23 = 0;
      for(Int_t im=69;im<105;im++){// small mods
	edep_12_23 += edepMod[im-1]; 
      }

                  
    }//for(Int_t iEventN=0;iEventN<gdTEvents;iEventN++)






}  
