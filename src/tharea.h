/**
 * @file tharea.h
 * Area module.
 */
  
/* Copyright (C) 2000 Stacho Mudrak
 * 
 * $Date: $
 * $RCSfile: $
 * $Revision: $
 *
 * -------------------------------------------------------------------- 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * -------------------------------------------------------------------- 
 */

#ifndef tharea_h
#define tharea_h


#include "th2ddataobject.h"
#include "thdb2dab.h"

/**
 * Area command options tokens.
 */
 
enum {
  TT_AREA_UNKNOWN = 3000,
  TT_AREA_TYPE = 3001,
};


/**
 * Area command options parsing table.
 */
 
static const thstok thtt_area_opt[] = {
  {NULL, TT_AREA_UNKNOWN},
};


/**
 * Area type tokens.
 */
 
enum {
  TT_AREA_TYPE_UNKNOWN,
  TT_AREA_TYPE_WATER,
  TT_AREA_TYPE_SUMP,
  TT_AREA_TYPE_SAND,
  TT_AREA_TYPE_DEBRIS,
};


/**
 * Area types parsing table.
 */
 
static const thstok thtt_area_types[] = {
  {"debris", TT_AREA_TYPE_DEBRIS},
  {"sand", TT_AREA_TYPE_SAND},
  {"sump", TT_AREA_TYPE_SUMP},
  {"water", TT_AREA_TYPE_WATER},
  {NULL, TT_AREA_TYPE_UNKNOWN},
};


/**
 * Area class.
 */

class tharea : public th2ddataobject {

  public:
  
  friend class thdb2d;

  int type;  ///< Area type.
  
  thdb2dab * first_line,  ///< First border line.
    * last_line;  ///< Last border line.
    
  void insert_border_line(int npars, char ** pars);  ///< Insert border line.

  public:

  /**
   * Standard constructor.
   */
  
  tharea();
  
  
  /**
   * Standard destructor.
   */
   
  ~tharea();
  
  
  /**
   * Return class identifier.
   */
  
  virtual int get_class_id();
  
  
  /**
   * Return class name.
   */
   
  virtual char * get_class_name() {return "tharea";};
  
  
  /**
   * Return true, if son of given class.
   */
  
  virtual bool is(int class_id);
  
  
  /**
   * Return number of command arguments.
   */
   
  virtual int get_cmd_nargs();
  
  
  /**
   * Return command name.
   */
   
  virtual char * get_cmd_name();
  
  
  /**
   * Return command end option.
   */
   
  virtual char * get_cmd_end();
  
  
  /**
   * Return option description.
   */
   
  virtual thcmd_option_desc get_cmd_option_desc(char * opts);
  
  
  /**
   * Set command option.
   *
   * @param cod Command option description.
   * @param args Option arguments arry.
   * @param argenc Arguments encoding.
   */
   
  virtual void set(thcmd_option_desc cod, char ** args, int argenc, unsigned long indataline);


  /**
   * Delete this object.
   *
   * @warn Always use this methos instead of delete function.
   */
   
  virtual void self_delete();


  /**
   * Print object properties.
   */
   
  virtual void self_print_properties(FILE * outf); 


  /**
   * Export to metapost file.
   */
   
  virtual void export_mp(class thexpmapmpxs * out);
  

};


#endif

