
#include "FLAME.h"

FLA_Error FLASH_Obj_attach_buffer_hierarchy_check( FLA_Obj F, FLA_Obj* H )
{
  FLA_Error e_val;

  e_val = FLA_Check_null_pointer( H );
  FLA_Check_error_code( e_val );

  return FLA_SUCCESS;
}
