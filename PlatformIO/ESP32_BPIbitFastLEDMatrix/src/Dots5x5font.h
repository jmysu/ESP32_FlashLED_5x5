/* 
  **  Font data for 5x5 Dots 5pt 
  * *      Dot Factory v.0.1.4
  */

/* Character bitmaps for 5x5 Dots 5pt */
//const uint_8 _5x5Dots_5ptBitmaps[] = 
static const unsigned char FontData[96][5] = 
{
    0x00,0x00,0x00,0x00,0x00, //space

	/* @0 '!' (1 pixels wide) */
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //  
	0x80, // #

	/* @5 '"' (3 pixels wide) */
	0xA0, // # #
	0xA0, // # #
	0x00, //    
	0x00, //    
	0x00, //    

	/* @10 '#' (5 pixels wide) */
	0x50, //  # # 
	0xF8, // #####
	0x50, //  # # 
	0xF8, // #####
	0x50, //  # # 

	/* @15 '$' (5 pixels wide) */
	0x78, //  ####
	0xA0, // # #  
	0x70, //  ### 
	0x28, //   # #
	0xF0, // #### 

	/* @20 '%' (5 pixels wide) */
	0x88, // #   #
	0x10, //    # 
	0x20, //   #  
	0x40, //  #   
	0x88, // #   #

	/* @25 '&' (5 pixels wide) */
	0x60, //  ##  
	0x90, // #  # 
	0x78, //  ####
	0x90, // #  # 
	0x78, //  ####

	/* @30 ''' (1 pixels wide) */
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  

	/* @35 '(' (2 pixels wide) */
	0x40, //  #
	0x80, // # 
	0x80, // # 
	0x80, // # 
	0x40, //  #

	/* @40 ')' (2 pixels wide) */
	0x80, // # 
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x80, // # 

	/* @45 '*' (5 pixels wide) */
	0x20, //   #  
	0xA8, // # # #
	0x70, //  ### 
	0xA8, // # # #
	0x20, //   #  

	/* @50 '+' (3 pixels wide) */
	0x00, //    
	0x40, //  # 
	0xE0, // ###
	0x40, //  # 
	0x00, //    

	/* @55 ',' (1 pixels wide) */
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x80, // #

	/* @60 '-' (3 pixels wide) */
	0x00, //    
	0x00, //    
	0xE0, // ###
	0x00, //    
	0x00, //    

	/* @65 '.' (1 pixels wide) */
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x80, // #

	/* @70 '/' (5 pixels wide) */
	0x08, //     #
	0x10, //    # 
	0x20, //   #  
	0x40, //  #   
	0x80, // #    

	/* @75 '0' (5 pixels wide) */
	0x70, //  ### 
	0x98, // #  ##
	0xA8, // # # #
	0xC8, // ##  #
	0x70, //  ### 

	/* @80 '1' (3 pixels wide) */
	0x40, //  # 
	0xC0, // ## 
	0x40, //  # 
	0x40, //  # 
	0xE0, // ###

	/* @85 '2' (5 pixels wide) */
	0xF0, // #### 
	0x08, //     #
	0x70, //  ### 
	0x80, // #    
	0xF8, // #####

	/* @90 '3' (5 pixels wide) */
	0xF0, // #### 
	0x08, //     #
	0x30, //   ## 
	0x08, //     #
	0xF0, // #### 

	/* @95 '4' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0x78, //  ####
	0x08, //     #
	0x08, //     #

	/* @100 '5' (5 pixels wide) */
	0xF8, // #####
	0x80, // #    
	0xF0, // #### 
	0x08, //     #
	0xF0, // #### 

	/* @105 '6' (5 pixels wide) */
	0x78, //  ####
	0x80, // #    
	0xF0, // #### 
	0x88, // #   #
	0x70, //  ### 

	/* @110 '7' (5 pixels wide) */
	0xF8, // #####
	0x08, //     #
	0x10, //    # 
	0x10, //    # 
	0x10, //    # 

	/* @115 '8' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0x70, //  ### 
	0x88, // #   #
	0x70, //  ### 

	/* @120 '9' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0x78, //  ####
	0x08, //     #
	0x30, //   ## 

	/* @125 ':' (1 pixels wide) */
	0x00, //  
	0x00, //  
	0x80, // #
	0x00, //  
	0x80, // #

	/* @130 ';' (1 pixels wide) */
	0x00, //  
	0x00, //  
	0x80, // #
	0x00, //  
	0x80, // #

	/* @135 '<' (3 pixels wide) */
	0x20, //   #
	0x40, //  # 
	0x80, // #  
	0x40, //  # 
	0x20, //   #

	/* @140 '=' (5 pixels wide) */
	0x00, //      
	0xF8, // #####
	0x00, //      
	0xF8, // #####
	0x00, //      

	/* @145 '>' (3 pixels wide) */
	0x80, // #  
	0x40, //  # 
	0x20, //   #
	0x40, //  # 
	0x80, // #  

	/* @150 '?' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0x30, //   ## 
	0x00, //      
	0x20, //   #  

	/* @155 '@' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0xA8, // # # #
	0x98, // #  ##
	0x60, //  ##  

	/* @160 'A' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0xF8, // #####
	0x88, // #   #
	0x88, // #   #

	/* @165 'B' (5 pixels wide) */
	0xF0, // #### 
	0x88, // #   #
	0xF0, // #### 
	0x88, // #   #
	0xF0, // #### 

	/* @170 'C' (5 pixels wide) */
	0x78, //  ####
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x78, //  ####

	/* @175 'D' (5 pixels wide) */
	0xF0, // #### 
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0xF0, // #### 

	/* @180 'E' (5 pixels wide) */
	0xF8, // #####
	0x80, // #    
	0xF8, // #####
	0x80, // #    
	0xF8, // #####

	/* @185 'F' (5 pixels wide) */
	0xF8, // #####
	0x80, // #    
	0xE0, // ###  
	0x80, // #    
	0x80, // #    

	/* @190 'G' (5 pixels wide) */
	0x78, //  ####
	0x80, // #    
	0xB8, // # ###
	0x88, // #   #
	0x78, //  ####

	/* @195 'H' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0xF8, // #####
	0x88, // #   #
	0x88, // #   #

	/* @200 'I' (1 pixels wide) */
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #

	/* @205 'J' (5 pixels wide) */
	0x38, //   ###
	0x08, //     #
	0x08, //     #
	0x88, // #   #
	0x70, //  ### 

	/* @210 'K' (5 pixels wide) */
	0x90, // #  # 
	0xA0, // # #  
	0xF0, // #### 
	0x88, // #   #
	0x88, // #   #

	/* @215 'L' (5 pixels wide) */
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0xF8, // #####

	/* @220 'M' (5 pixels wide) */
	0x88, // #   #
	0xD8, // ## ##
	0xA8, // # # #
	0x88, // #   #
	0x88, // #   #

	/* @225 'N' (5 pixels wide) */
	0xC8, // ##  #
	0xA8, // # # #
	0xA8, // # # #
	0xA8, // # # #
	0x98, // #  ##

	/* @230 'O' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x70, //  ### 

	/* @235 'P' (5 pixels wide) */
	0xF0, // #### 
	0x88, // #   #
	0xF0, // #### 
	0x80, // #    
	0x80, // #    

	/* @240 'Q' (5 pixels wide) */
	0x60, //  ##  
	0x90, // #  # 
	0x90, // #  # 
	0x90, // #  # 
	0x78, //  ####

	/* @245 'R' (5 pixels wide) */
	0xF0, // #### 
	0x88, // #   #
	0xF0, // #### 
	0x90, // #  # 
	0x88, // #   #

	/* @250 'S' (5 pixels wide) */
	0x78, //  ####
	0x80, // #    
	0x70, //  ### 
	0x08, //     #
	0xF0, // #### 

	/* @255 'T' (5 pixels wide) */
	0xF8, // #####
	0x20, //   #  
	0x20, //   #  
	0x20, //   #  
	0x20, //   #  

	/* @260 'U' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x70, //  ### 

	/* @265 'V' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0x50, //  # # 
	0x50, //  # # 
	0x20, //   #  

	/* @270 'W' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0xA8, // # # #
	0xD8, // ## ##
	0x88, // #   #

	/* @275 'X' (5 pixels wide) */
	0x88, // #   #
	0x50, //  # # 
	0x20, //   #  
	0x50, //  # # 
	0x88, // #   #

	/* @280 'Y' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0x70, //  ### 
	0x20, //   #  
	0x20, //   #  

	/* @285 'Z' (5 pixels wide) */
	0xF8, // #####
	0x08, //     #
	0x70, //  ### 
	0x80, // #    
	0xF8, // #####

	/* @290 '[' (2 pixels wide) */
	0xC0, // ##
	0x80, // # 
	0x80, // # 
	0x80, // # 
	0xC0, // ##

	/* @295 '\' (5 pixels wide) */
	0x80, // #    
	0x40, //  #   
	0x20, //   #  
	0x10, //    # 
	0x08, //     #

	/* @300 ']' (2 pixels wide) */
	0xC0, // ##
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0xC0, // ##

	/* @305 '^' (3 pixels wide) */
	0x40, //  # 
	0xA0, // # #
	0x00, //    
	0x00, //    
	0x00, //    

	/* @310 '_' (5 pixels wide) */
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0xF8, // #####

	/* @315 '`' (1 pixels wide) */
	0x80, // #
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  

	/* @320 'a' (5 pixels wide) */
	0xF0, // #### 
	0x08, //     #
	0x78, //  ####
	0x88, // #   #
	0x78, //  ####

	/* @325 'b' (5 pixels wide) */
	0x80, // #    
	0xF0, // #### 
	0x88, // #   #
	0x88, // #   #
	0xF0, // #### 

	/* @330 'c' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0x80, // #    
	0x88, // #   #
	0x70, //  ### 

	/* @335 'd' (5 pixels wide) */
	0x08, //     #
	0x78, //  ####
	0x88, // #   #
	0x88, // #   #
	0x78, //  ####

	/* @340 'e' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0xF8, // #####
	0x80, // #    
	0x78, //  ####

	/* @345 'f' (5 pixels wide) */
	0x78, //  ####
	0x80, // #    
	0xE0, // ###  
	0x80, // #    
	0x80, // #    

	/* @350 'g' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0x78, //  ####
	0x08, //     #
	0xF0, // #### 

	/* @355 'h' (5 pixels wide) */
	0x80, // #    
	0xF0, // #### 
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #

	/* @360 'i' (1 pixels wide) */
	0x80, // #
	0x00, //  
	0x80, // #
	0x80, // #
	0x80, // #

	/* @365 'j' (5 pixels wide) */
	0x08, //     #
	0x08, //     #
	0x08, //     #
	0x08, //     #
	0xF0, // #### 

	/* @370 'k' (5 pixels wide) */
	0x88, // #   #
	0x90, // #  # 
	0xE0, // ###  
	0x90, // #  # 
	0x88, // #   #

	/* @375 'l' (5 pixels wide) */
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x78, //  ####

	/* @380 'm' (5 pixels wide) */
	0x50, //  # # 
	0xA8, // # # #
	0xA8, // # # #
	0xA8, // # # #
	0xA8, // # # #

	/* @385 'n' (5 pixels wide) */
	0xF0, // #### 
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #

	/* @390 'o' (5 pixels wide) */
	0x70, //  ### 
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x70, //  ### 

	/* @395 'p' (5 pixels wide) */
	0xF0, // #### 
	0x88, // #   #
	0x88, // #   #
	0xF0, // #### 
	0x80, // #    

	/* @400 'q' (5 pixels wide) */
	0x78, //  ####
	0x88, // #   #
	0x88, // #   #
	0x78, //  ####
	0x08, //     #

	/* @405 'r' (5 pixels wide) */
	0xB0, // # ## 
	0xC8, // ##  #
	0x80, // #    
	0x80, // #    
	0x80, // #    

	/* @410 's' (5 pixels wide) */
	0x78, //  ####
	0x80, // #    
	0x70, //  ### 
	0x08, //     #
	0xF0, // #### 

	/* @415 't' (5 pixels wide) */
	0x80, // #    
	0xE0, // ###  
	0x80, // #    
	0x88, // #   #
	0x70, //  ### 

	/* @420 'u' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x98, // #  ##
	0x68, //  ## #

	/* @425 'v' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0x50, //  # # 
	0x50, //  # # 
	0x20, //   #  

	/* @430 'w' (5 pixels wide) */
	0xA8, // # # #
	0xA8, // # # #
	0xA8, // # # #
	0xA8, // # # #
	0x50, //  # # 

	/* @435 'x' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0x70, //  ### 
	0x88, // #   #
	0x88, // #   #

	/* @440 'y' (5 pixels wide) */
	0x88, // #   #
	0x88, // #   #
	0x78, //  ####
	0x08, //     #
	0xF0, // #### 

	/* @445 'z' (5 pixels wide) */
	0xF8, // #####
	0x10, //    # 
	0x20, //   #  
	0x40, //  #   
	0xF8, // #####

	/* @450 '{' (3 pixels wide) */
	0x20, //   #
	0x40, //  # 
	0xC0, // ## 
	0x40, //  # 
	0x20, //   #

	/* @455 '|' (1 pixels wide) */
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #

	/* @460 '}' (3 pixels wide) */
	0x80, // #  
	0x40, //  # 
	0x60, //  ##
	0x40, //  # 
	0x80, // #  

	/* @465 '~' (4 pixels wide) */
	0x50, //  # #
	0xA0, // # # 
	0x00, //     
	0x00, //     
	0x00 //     
};
