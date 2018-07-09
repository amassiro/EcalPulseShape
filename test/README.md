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
    
    
    
    
    
