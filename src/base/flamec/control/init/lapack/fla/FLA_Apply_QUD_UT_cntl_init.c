
#include "FLAME.h"

extern fla_gemm_t*  fla_gemm_cntl_blas;
extern fla_trsm_t*  fla_trsm_cntl_blas;
extern fla_copyt_t* fla_copyt_cntl_blas;
extern fla_axpyt_t* fla_axpyt_cntl_blas;

fla_apqudut_t*      fla_apqudut_cntl_leaf;
fla_blocksize_t*    fla_apqudut_var1_bsize;

void FLA_Apply_QUD_UT_cntl_init()
{
	// Set the blocksize to the default value for conventional storage,
	// but scaled down.
	fla_apqudut_var1_bsize = FLA_Query_blocksizes( FLA_DIMENSION_MIN );
	FLA_Blocksize_scale( fla_apqudut_var1_bsize, FLA_UDDATE_INNER_TO_OUTER_B_RATIO );

	// Create a control tree to invoke variant 1.
	fla_apqudut_cntl_leaf = FLA_Cntl_apqudut_obj_create( FLA_FLAT,
	                                                     FLA_BLOCKED_VARIANT1, 
	                                                     fla_apqudut_var1_bsize,
	                                                     NULL,
	                                                     fla_gemm_cntl_blas,
	                                                     fla_gemm_cntl_blas,
	                                                     fla_gemm_cntl_blas,
	                                                     fla_gemm_cntl_blas,
	                                                     fla_trsm_cntl_blas,
	                                                     fla_copyt_cntl_blas,
	                                                     fla_axpyt_cntl_blas );
}

void FLA_Apply_QUD_UT_cntl_finalize()
{
	FLA_Cntl_obj_free( fla_apqudut_cntl_leaf );

	FLA_Blocksize_free( fla_apqudut_var1_bsize );
}
