Steps

1) download two set of pulse shapes

2) simulate with one set and fit with the second

3) plot the bias



                                            simulate    fit
    download  EcalPulseShapes_Legacy2016_v2    1         2
    
    download  EcalPulseShapes_Legacy2016_v2    2         3
    

    download  EcalPulseShapes_Legacy2016_v2    5        6

    download  EcalPulseShapes_Legacy2016_v2    5        5

    
    r99t test/draw.cxx
    
    
    
    
    r99t test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt318745_317506-amplitude-10.root\"\)
    r99t test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt318745_317506-amplitude-100.root\"\)
    r99t test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt318745_317506-amplitude-1000.root\"\)
    
    
    
    r99t test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3304911_304209-amp10.root\"\)
    r99t test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3304911_304209-amp100.root\"\)
    r99t test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3304911_304209-amp1000.root\"\)
    
    
    
    
    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_307013_306121.root\",20,40,1\)
    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_307013_306121.root\",63,50,-1\)
    
    
    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_293999_283863.root\",63,50,-1\)
    
    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_301472_301141.root\",41,91,-1,1\)
    r99t test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_301472_301141.root\"\)

    
    
    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_300202_297681.root\",41,91,-1,0\)
    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_300202_297681.root\",-15,107,0,1\)
    
    
    
    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_293999_293999.root\",-15,107,0,1\)
    
    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_275757_274958.root\",-59,112,0,1\)
    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_275757_274958.root\",-43,243,0,1\)

    r99t test/drawPulse.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_275757_274958.root\",50,18,1,1\)
    
    
    
Legacy 2016:

    https://cms-conddb.cern.ch/cmsDbBrowser/list/Prod/gts/80X_dataRun2_2016LegacyRepro_v4
    
    EcalPulseShapes_Legacy2016_v2
    
    
    scan_all EcalPulseShapes_Legacy2016_v2  3
    
    scan_all EcalPulseShapes_Legacy2016_v2  6
    
    scan_all EcalPulseShapes_Legacy2016_v2  25

    
    scan_all EcalPulseShapes_October2017_rereco_v3  15
    
    
    New tag
    ----

    scan_all   EcalPulseShapes_data    1    sqlite_file:/afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/ecaltemplates_popcon_Ultimate2016_calib.db 
    scan_all   EcalPulseShapes_data   23    sqlite_file:/afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/ecaltemplates_popcon_Ultimate2016_calib.db 
    
    
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_283863_283171.root\"\);     mkdir Legacy2016_v3_283863_283171/;   cp *.png  Legacy2016_v3_283863_283171/;     cp index.php  Legacy2016_v3_283863_283171/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_283171_282730.root\"\);     mkdir Legacy2016_v3_283171_282730/;   cp *.png  Legacy2016_v3_283171_282730/;     cp index.php  Legacy2016_v3_283171_282730/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_282730_282408.root\"\);     mkdir Legacy2016_v3_282730_282408/;   cp *.png  Legacy2016_v3_282730_282408/;     cp index.php  Legacy2016_v3_282730_282408/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_282408_281010.root\"\);     mkdir Legacy2016_v3_282408_281010/;   cp *.png  Legacy2016_v3_282408_281010/;     cp index.php  Legacy2016_v3_282408_281010/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_281010_280327.root\"\);     mkdir Legacy2016_v3_281010_280327/;   cp *.png  Legacy2016_v3_281010_280327/;     cp index.php  Legacy2016_v3_281010_280327/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_280327_279993.root\"\);     mkdir Legacy2016_v3_280327_279993/;   cp *.png  Legacy2016_v3_280327_279993/;     cp index.php  Legacy2016_v3_280327_279993/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_279993_279717.root\"\);     mkdir Legacy2016_v3_279993_279717/;   cp *.png  Legacy2016_v3_279993_279717/;     cp index.php  Legacy2016_v3_279993_279717/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_279717_279715.root\"\);     mkdir Legacy2016_v3_279717_279715/;   cp *.png  Legacy2016_v3_279717_279715/;     cp index.php  Legacy2016_v3_279717_279715/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_279715_279474.root\"\);     mkdir Legacy2016_v3_279715_279474/;   cp *.png  Legacy2016_v3_279715_279474/;     cp index.php  Legacy2016_v3_279715_279474/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_279474_278977.root\"\);     mkdir Legacy2016_v3_279474_278977/;   cp *.png  Legacy2016_v3_279474_278977/;     cp index.php  Legacy2016_v3_279474_278977/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_278977_278346.root\"\);     mkdir Legacy2016_v3_278977_278346/;   cp *.png  Legacy2016_v3_278977_278346/;     cp index.php  Legacy2016_v3_278977_278346/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_278346_277932.root\"\);     mkdir Legacy2016_v3_278346_277932/;   cp *.png  Legacy2016_v3_278346_277932/;     cp index.php  Legacy2016_v3_278346_277932/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_277932_276775.root\"\);     mkdir Legacy2016_v3_277932_276775/;   cp *.png  Legacy2016_v3_277932_276775/;     cp index.php  Legacy2016_v3_277932_276775/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_276775_276525.root\"\);     mkdir Legacy2016_v3_276775_276525/;   cp *.png  Legacy2016_v3_276775_276525/;     cp index.php  Legacy2016_v3_276775_276525/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_276525_276282.root\"\);     mkdir Legacy2016_v3_276525_276282/;   cp *.png  Legacy2016_v3_276525_276282/;     cp index.php  Legacy2016_v3_276525_276282/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_276282_275886.root\"\);     mkdir Legacy2016_v3_276282_275886/;   cp *.png  Legacy2016_v3_276282_275886/;     cp index.php  Legacy2016_v3_276282_275886/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_275886_275656.root\"\);     mkdir Legacy2016_v3_275886_275656/;   cp *.png  Legacy2016_v3_275886_275656/;     cp index.php  Legacy2016_v3_275886_275656/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_275656_275282.root\"\);     mkdir Legacy2016_v3_275656_275282/;   cp *.png  Legacy2016_v3_275656_275282/;     cp index.php  Legacy2016_v3_275656_275282/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_275282_274958.root\"\);     mkdir Legacy2016_v3_275282_274958/;   cp *.png  Legacy2016_v3_275282_274958/;     cp index.php  Legacy2016_v3_275282_274958/  
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_data_EcalPulseShapes_data_274958_274080.root\"\);     mkdir Legacy2016_v3_274958_274080/;   cp *.png  Legacy2016_v3_274958_274080/;     cp index.php  Legacy2016_v3_274958_274080/  


    
    
    r99t test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt318745_317506.root\"\)
    
    
    
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt_318745_317506.root\"\)  ;      mkdir hlt_318745_317506/     ;           cp *.png  hlt_318745_317506/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt_317506_316570.root\"\)  ;      mkdir hlt_317506_316570/     ;           cp *.png  hlt_317506_316570/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt_316570_316361.root\"\)  ;      mkdir hlt_316570_316361/     ;           cp *.png  hlt_316570_316361/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt_316361_315344.root\"\)  ;      mkdir hlt_316361_315344/     ;           cp *.png  hlt_316361_315344/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt_315344_314765.root\"\)  ;      mkdir hlt_315344_314765/     ;           cp *.png  hlt_315344_314765/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_hlt_EcalPulseShapes_hlt_314765_307555.root\"\)  ;      mkdir hlt_314765_307555/     ;           cp *.png  hlt_314765_307555/       ;

    
    https://cms-conddb.cern.ch/cmsDbBrowser/list/Prod/tags/EcalPulseShapes_Legacy2016_v2
    
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_300666_300202.root\"\)  ;      mkdir Legacy2016_v2_300666_300202/     ;           cp *.png  Legacy2016_v2_300666_300202/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_300202_297681.root\"\)  ;      mkdir Legacy2016_v2_300202_297681/     ;           cp *.png  Legacy2016_v2_300202_297681/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_297681_296184.root\"\)  ;      mkdir Legacy2016_v2_297681_296184/     ;           cp *.png  Legacy2016_v2_297681_296184/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_296184_293999.root\"\)  ;      mkdir Legacy2016_v2_296184_293999/     ;           cp *.png  Legacy2016_v2_296184_293999/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_293999_283863.root\"\)  ;      mkdir Legacy2016_v2_293999_283863/     ;           cp *.png  Legacy2016_v2_293999_283863/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_283863_283171.root\"\)  ;      mkdir Legacy2016_v2_283863_283171/     ;           cp *.png  Legacy2016_v2_283863_283171/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_283171_282408.root\"\)  ;      mkdir Legacy2016_v2_283171_282408/     ;           cp *.png  Legacy2016_v2_283171_282408/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_282408_281010.root\"\)  ;      mkdir Legacy2016_v2_282408_281010/     ;           cp *.png  Legacy2016_v2_282408_281010/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_281010_279717.root\"\)  ;      mkdir Legacy2016_v2_281010_279717/     ;           cp *.png  Legacy2016_v2_281010_279717/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_279717_279474.root\"\)  ;      mkdir Legacy2016_v2_279717_279474/     ;           cp *.png  Legacy2016_v2_279717_279474/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_279474_278977.root\"\)  ;      mkdir Legacy2016_v2_279474_278977/     ;           cp *.png  Legacy2016_v2_279474_278977/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_278977_278346.root\"\)  ;      mkdir Legacy2016_v2_278977_278346/     ;           cp *.png  Legacy2016_v2_278977_278346/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_278346_277932.root\"\)  ;      mkdir Legacy2016_v2_278346_277932/     ;           cp *.png  Legacy2016_v2_278346_277932/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_277932_276315.root\"\)  ;      mkdir Legacy2016_v2_277932_276315/     ;           cp *.png  Legacy2016_v2_277932_276315/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_276315_275757.root\"\)  ;      mkdir Legacy2016_v2_276315_275757/     ;           cp *.png  Legacy2016_v2_276315_275757/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_275757_274958.root\"\)  ;      mkdir Legacy2016_v2_275757_274958/     ;           cp *.png  Legacy2016_v2_275757_274958/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_274958_274080.root\"\)  ;      mkdir Legacy2016_v2_274958_274080/     ;           cp *.png  Legacy2016_v2_274958_274080/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_274080_272818.root\"\)  ;      mkdir Legacy2016_v2_274080_272818/     ;           cp *.png  Legacy2016_v2_274080_272818/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_272818_271865.root\"\)  ;      mkdir Legacy2016_v2_272818_271865/     ;           cp *.png  Legacy2016_v2_272818_271865/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_271865_258601.root\"\)  ;      mkdir Legacy2016_v2_271865_258601/     ;           cp *.png  Legacy2016_v2_271865_258601/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_Legacy2016_v2_EcalPulseShapes_Legacy2016_v2_258601_257615.root\"\)  ;      mkdir Legacy2016_v2_258601_257615/     ;           cp *.png  Legacy2016_v2_258601_257615/       ;



    
    cp  index.php   Legacy2016_v2_300666_300202/
    cp  index.php   Legacy2016_v2_300202_297681/
    cp  index.php   Legacy2016_v2_297681_296184/
    cp  index.php   Legacy2016_v2_296184_293999/
    cp  index.php   Legacy2016_v2_293999_283863/
    cp  index.php   Legacy2016_v2_283863_283171/
    cp  index.php   Legacy2016_v2_283171_282408/
    cp  index.php   Legacy2016_v2_282408_281010/  
    cp  index.php   Legacy2016_v2_281010_279717/  
    cp  index.php   Legacy2016_v2_279717_279474/  
    cp  index.php   Legacy2016_v2_279474_278977/  
    cp  index.php   Legacy2016_v2_278977_278346/  
    cp  index.php   Legacy2016_v2_278346_277932/  
    cp  index.php   Legacy2016_v2_277932_276315/  
    cp  index.php   Legacy2016_v2_276315_275757/  
    cp  index.php   Legacy2016_v2_275757_274958/  
    cp  index.php   Legacy2016_v2_274958_274080/  
    cp  index.php   Legacy2016_v2_274080_272818/  
    cp  index.php   Legacy2016_v2_272818_271865/  
    cp  index.php   Legacy2016_v2_271865_258601/  
    cp  index.php   Legacy2016_v2_258601_257615/  
    
    
    
    
    
    
    
    https://cms-conddb.cern.ch/cmsDbBrowser/list/Prod/tags/EcalPulseShapes_October2017_rereco_v3
    
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_307013_306121.root\"\)  ;      mkdir Legacy2017_307013_306121/     ;    cp *.png  Legacy2017_307013_306121/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_306121_305832.root\"\)  ;      mkdir Legacy2017_306121_305832/     ;    cp *.png  Legacy2017_306121_305832/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_305832_305814.root\"\)  ;      mkdir Legacy2017_305832_305814/     ;    cp *.png  Legacy2017_305832_305814/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_305814_304911.root\"\)  ;      mkdir Legacy2017_305814_304911/     ;    cp *.png  Legacy2017_305814_304911/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_304911_304209.root\"\)  ;      mkdir Legacy2017_304911_304209/     ;    cp *.png  Legacy2017_304911_304209/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_304209_301472.root\"\)  ;      mkdir Legacy2017_304209_301472/     ;    cp *.png  Legacy2017_304209_301472/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_301472_301141.root\"\)  ;      mkdir Legacy2017_301472_301141/     ;    cp *.png  Legacy2017_301472_301141/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_301141_300574.root\"\)  ;      mkdir Legacy2017_301141_300574/     ;    cp *.png  Legacy2017_301141_300574/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_300574_300122.root\"\)  ;      mkdir Legacy2017_300574_300122/     ;    cp *.png  Legacy2017_300574_300122/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_300122_300079.root\"\)  ;      mkdir Legacy2017_300122_300079/     ;    cp *.png  Legacy2017_300122_300079/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_300079_299067.root\"\)  ;      mkdir Legacy2017_300079_299067/     ;    cp *.png  Legacy2017_300079_299067/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_299067_298809.root\"\)  ;      mkdir Legacy2017_299067_298809/     ;    cp *.png  Legacy2017_299067_298809/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_298809_297113.root\"\)  ;      mkdir Legacy2017_298809_297113/     ;    cp *.png  Legacy2017_298809_297113/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_297113_293765.root\"\)  ;      mkdir Legacy2017_297113_293765/     ;    cp *.png  Legacy2017_297113_293765/       ;
    r99t -q   test/draw.cxx\(\"out_EcalPulseShapes_October2017_rereco_v3_EcalPulseShapes_October2017_rereco_v3_293765_283863.root\"\)  ;      mkdir Legacy2017_293765_283863/     ;    cp *.png  Legacy2017_293765_283863/       ;
    
    
    

Simulation time shift:

    Prepare tags
    
    Inputs: https://adarold.web.cern.ch/adarold/everycrystal_par.txt
    2017 time scan (1 ns time scan)
    
    
    
test:

    cmsRun test/Ecal_PulseShapes_argv_cfg.py   template_histograms_ECAL_Run2015C_lowPU.txt
    
    download  EcalPulseShapes_data     1        1       file:ecaltemplates_popcon_runs.db
       
    
Study time shift:

    TimeShiftAnalysis     data/everycrystal_par.txt     -10      10      100
    TimeShiftAnalysis     data/everycrystal_par.txt     -10      10      1000
    
    r99t test/draw.cxx\(\"out_time_scan_-10.000000.root\"\)     
    r99t test/draw.cxx\(\"out_time_scan_-1.000000.root\"\) 
    
    r99t test/drawPulse.cxx\(\"out_time_scan_-10.000000.root\",50,18,0,1\)
    
    
    
    r99t test/draw.cxx\(\"out_time_scan_-1.000000.root\"\) 
    r99t test/draw.cxx\(\"out_time_scan_0.630000.root\"\) 
    r99t test/draw.cxx\(\"out_time_scan_0.000000.root\"\) 

    r99t test/drawPulse.cxx\(\"out_time_scan_0.630000.root\",50,18,1,1\)
    r99t test/drawPulse.cxx\(\"out_time_scan_0.000000.root\",50,18,1,1\)
    
    r99t test/drawPulse.cxx\(\"out_time_scan_0.630000.root\",50,18,0,1\)
    r99t test/drawPulse.cxx\(\"out_time_scan_0.990000.root\",50,18,0,1\)
    
    
    
    
    
    
    
    
    

    
