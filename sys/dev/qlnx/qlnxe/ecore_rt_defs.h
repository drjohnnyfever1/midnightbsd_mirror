/* $MidnightBSD$ */
/*
 * Copyright (c) 2017-2018 Cavium, Inc. 
 * All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD: stable/10/sys/dev/qlnx/qlnxe/ecore_rt_defs.h 320162 2017-06-20 18:52:35Z davidcs $
 *
 */


#ifndef __RT_DEFS_H__
#define __RT_DEFS_H__

/* Runtime array offsets */
#define DORQ_REG_PF_MAX_ICID_0_RT_OFFSET                            	0
#define DORQ_REG_PF_MAX_ICID_1_RT_OFFSET                            	1
#define DORQ_REG_PF_MAX_ICID_2_RT_OFFSET                            	2
#define DORQ_REG_PF_MAX_ICID_3_RT_OFFSET                            	3
#define DORQ_REG_PF_MAX_ICID_4_RT_OFFSET                            	4
#define DORQ_REG_PF_MAX_ICID_5_RT_OFFSET                            	5
#define DORQ_REG_PF_MAX_ICID_6_RT_OFFSET                            	6
#define DORQ_REG_PF_MAX_ICID_7_RT_OFFSET                            	7
#define DORQ_REG_VF_MAX_ICID_0_RT_OFFSET                            	8
#define DORQ_REG_VF_MAX_ICID_1_RT_OFFSET                            	9
#define DORQ_REG_VF_MAX_ICID_2_RT_OFFSET                            	10
#define DORQ_REG_VF_MAX_ICID_3_RT_OFFSET                            	11
#define DORQ_REG_VF_MAX_ICID_4_RT_OFFSET                            	12
#define DORQ_REG_VF_MAX_ICID_5_RT_OFFSET                            	13
#define DORQ_REG_VF_MAX_ICID_6_RT_OFFSET                            	14
#define DORQ_REG_VF_MAX_ICID_7_RT_OFFSET                            	15
#define DORQ_REG_PF_WAKE_ALL_RT_OFFSET                              	16
#define DORQ_REG_TAG1_ETHERTYPE_RT_OFFSET                           	17
#define IGU_REG_PF_CONFIGURATION_RT_OFFSET                          	18
#define IGU_REG_VF_CONFIGURATION_RT_OFFSET                          	19
#define IGU_REG_ATTN_MSG_ADDR_L_RT_OFFSET                           	20
#define IGU_REG_ATTN_MSG_ADDR_H_RT_OFFSET                           	21
#define IGU_REG_LEADING_EDGE_LATCH_RT_OFFSET                        	22
#define IGU_REG_TRAILING_EDGE_LATCH_RT_OFFSET                       	23
#define CAU_REG_CQE_AGG_UNIT_SIZE_RT_OFFSET                         	24
#define CAU_REG_SB_VAR_MEMORY_RT_OFFSET                             	1049
#define CAU_REG_SB_VAR_MEMORY_RT_SIZE                               	1024
#define CAU_REG_SB_VAR_MEMORY_RT_OFFSET                             	1049
#define CAU_REG_SB_VAR_MEMORY_RT_SIZE                               	1024
#define CAU_REG_SB_ADDR_MEMORY_RT_OFFSET                            	2073
#define CAU_REG_SB_ADDR_MEMORY_RT_SIZE                              	1024
#define CAU_REG_PI_MEMORY_RT_OFFSET                                 	3097
#define CAU_REG_PI_MEMORY_RT_SIZE                                   	4416
#define PRS_REG_SEARCH_RESP_INITIATOR_TYPE_RT_OFFSET                	7513
#define PRS_REG_TASK_ID_MAX_INITIATOR_PF_RT_OFFSET                  	7514
#define PRS_REG_TASK_ID_MAX_INITIATOR_VF_RT_OFFSET                  	7515
#define PRS_REG_TASK_ID_MAX_TARGET_PF_RT_OFFSET                     	7516
#define PRS_REG_TASK_ID_MAX_TARGET_VF_RT_OFFSET                     	7517
#define PRS_REG_SEARCH_TCP_RT_OFFSET                                	7518
#define PRS_REG_SEARCH_FCOE_RT_OFFSET                               	7519
#define PRS_REG_SEARCH_ROCE_RT_OFFSET                               	7520
#define PRS_REG_ROCE_DEST_QP_MAX_VF_RT_OFFSET                       	7521
#define PRS_REG_ROCE_DEST_QP_MAX_PF_RT_OFFSET                       	7522
#define PRS_REG_SEARCH_OPENFLOW_RT_OFFSET                           	7523
#define PRS_REG_SEARCH_NON_IP_AS_OPENFLOW_RT_OFFSET                 	7524
#define PRS_REG_OPENFLOW_SUPPORT_ONLY_KNOWN_OVER_IP_RT_OFFSET       	7525
#define PRS_REG_OPENFLOW_SEARCH_KEY_MASK_RT_OFFSET                  	7526
#define PRS_REG_TAG_ETHERTYPE_0_RT_OFFSET                           	7527
#define PRS_REG_LIGHT_L2_ETHERTYPE_EN_RT_OFFSET                     	7528
#define SRC_REG_FIRSTFREE_RT_OFFSET                                 	7529
#define SRC_REG_FIRSTFREE_RT_SIZE                                   	2
#define SRC_REG_LASTFREE_RT_OFFSET                                  	7531
#define SRC_REG_LASTFREE_RT_SIZE                                    	2
#define SRC_REG_COUNTFREE_RT_OFFSET                                 	7533
#define SRC_REG_NUMBER_HASH_BITS_RT_OFFSET                          	7534
#define PSWRQ2_REG_CDUT_P_SIZE_RT_OFFSET                            	7535
#define PSWRQ2_REG_CDUC_P_SIZE_RT_OFFSET                            	7536
#define PSWRQ2_REG_TM_P_SIZE_RT_OFFSET                              	7537
#define PSWRQ2_REG_QM_P_SIZE_RT_OFFSET                              	7538
#define PSWRQ2_REG_SRC_P_SIZE_RT_OFFSET                             	7539
#define PSWRQ2_REG_TSDM_P_SIZE_RT_OFFSET                            	7540
#define PSWRQ2_REG_TM_FIRST_ILT_RT_OFFSET                           	7541
#define PSWRQ2_REG_TM_LAST_ILT_RT_OFFSET                            	7542
#define PSWRQ2_REG_QM_FIRST_ILT_RT_OFFSET                           	7543
#define PSWRQ2_REG_QM_LAST_ILT_RT_OFFSET                            	7544
#define PSWRQ2_REG_SRC_FIRST_ILT_RT_OFFSET                          	7545
#define PSWRQ2_REG_SRC_LAST_ILT_RT_OFFSET                           	7546
#define PSWRQ2_REG_CDUC_FIRST_ILT_RT_OFFSET                         	7547
#define PSWRQ2_REG_CDUC_LAST_ILT_RT_OFFSET                          	7548
#define PSWRQ2_REG_CDUT_FIRST_ILT_RT_OFFSET                         	7549
#define PSWRQ2_REG_CDUT_LAST_ILT_RT_OFFSET                          	7550
#define PSWRQ2_REG_TSDM_FIRST_ILT_RT_OFFSET                         	7551
#define PSWRQ2_REG_TSDM_LAST_ILT_RT_OFFSET                          	7552
#define PSWRQ2_REG_TM_NUMBER_OF_PF_BLOCKS_RT_OFFSET                 	7553
#define PSWRQ2_REG_CDUT_NUMBER_OF_PF_BLOCKS_RT_OFFSET               	7554
#define PSWRQ2_REG_CDUC_NUMBER_OF_PF_BLOCKS_RT_OFFSET               	7555
#define PSWRQ2_REG_TM_VF_BLOCKS_RT_OFFSET                           	7556
#define PSWRQ2_REG_CDUT_VF_BLOCKS_RT_OFFSET                         	7557
#define PSWRQ2_REG_CDUC_VF_BLOCKS_RT_OFFSET                         	7558
#define PSWRQ2_REG_TM_BLOCKS_FACTOR_RT_OFFSET                       	7559
#define PSWRQ2_REG_CDUT_BLOCKS_FACTOR_RT_OFFSET                     	7560
#define PSWRQ2_REG_CDUC_BLOCKS_FACTOR_RT_OFFSET                     	7561
#define PSWRQ2_REG_VF_BASE_RT_OFFSET                                	7562
#define PSWRQ2_REG_VF_LAST_ILT_RT_OFFSET                            	7563
#define PSWRQ2_REG_DRAM_ALIGN_WR_RT_OFFSET                          	7564
#define PSWRQ2_REG_DRAM_ALIGN_RD_RT_OFFSET                          	7565
#define PSWRQ2_REG_ILT_MEMORY_RT_OFFSET                             	7566
#define PSWRQ2_REG_ILT_MEMORY_RT_SIZE                               	22000
#define PGLUE_REG_B_VF_BASE_RT_OFFSET                               	29566
#define PGLUE_REG_B_MSDM_OFFSET_MASK_B_RT_OFFSET                    	29567
#define PGLUE_REG_B_MSDM_VF_SHIFT_B_RT_OFFSET                       	29568
#define PGLUE_REG_B_CACHE_LINE_SIZE_RT_OFFSET                       	29569
#define PGLUE_REG_B_PF_BAR0_SIZE_RT_OFFSET                          	29570
#define PGLUE_REG_B_PF_BAR1_SIZE_RT_OFFSET                          	29571
#define PGLUE_REG_B_VF_BAR1_SIZE_RT_OFFSET                          	29572
#define TM_REG_VF_ENABLE_CONN_RT_OFFSET                             	29573
#define TM_REG_PF_ENABLE_CONN_RT_OFFSET                             	29574
#define TM_REG_PF_ENABLE_TASK_RT_OFFSET                             	29575
#define TM_REG_GROUP_SIZE_RESOLUTION_CONN_RT_OFFSET                 	29576
#define TM_REG_GROUP_SIZE_RESOLUTION_TASK_RT_OFFSET                 	29577
#define TM_REG_CONFIG_CONN_MEM_RT_OFFSET                            	29578
#define TM_REG_CONFIG_CONN_MEM_RT_SIZE                              	416
#define TM_REG_CONFIG_TASK_MEM_RT_OFFSET                            	29994
#define TM_REG_CONFIG_TASK_MEM_RT_SIZE                              	608
#define QM_REG_MAXPQSIZE_0_RT_OFFSET                                	30602
#define QM_REG_MAXPQSIZE_1_RT_OFFSET                                	30603
#define QM_REG_MAXPQSIZE_2_RT_OFFSET                                	30604
#define QM_REG_MAXPQSIZETXSEL_0_RT_OFFSET                           	30605
#define QM_REG_MAXPQSIZETXSEL_1_RT_OFFSET                           	30606
#define QM_REG_MAXPQSIZETXSEL_2_RT_OFFSET                           	30607
#define QM_REG_MAXPQSIZETXSEL_3_RT_OFFSET                           	30608
#define QM_REG_MAXPQSIZETXSEL_4_RT_OFFSET                           	30609
#define QM_REG_MAXPQSIZETXSEL_5_RT_OFFSET                           	30610
#define QM_REG_MAXPQSIZETXSEL_6_RT_OFFSET                           	30611
#define QM_REG_MAXPQSIZETXSEL_7_RT_OFFSET                           	30612
#define QM_REG_MAXPQSIZETXSEL_8_RT_OFFSET                           	30613
#define QM_REG_MAXPQSIZETXSEL_9_RT_OFFSET                           	30614
#define QM_REG_MAXPQSIZETXSEL_10_RT_OFFSET                          	30615
#define QM_REG_MAXPQSIZETXSEL_11_RT_OFFSET                          	30616
#define QM_REG_MAXPQSIZETXSEL_12_RT_OFFSET                          	30617
#define QM_REG_MAXPQSIZETXSEL_13_RT_OFFSET                          	30618
#define QM_REG_MAXPQSIZETXSEL_14_RT_OFFSET                          	30619
#define QM_REG_MAXPQSIZETXSEL_15_RT_OFFSET                          	30620
#define QM_REG_MAXPQSIZETXSEL_16_RT_OFFSET                          	30621
#define QM_REG_MAXPQSIZETXSEL_17_RT_OFFSET                          	30622
#define QM_REG_MAXPQSIZETXSEL_18_RT_OFFSET                          	30623
#define QM_REG_MAXPQSIZETXSEL_19_RT_OFFSET                          	30624
#define QM_REG_MAXPQSIZETXSEL_20_RT_OFFSET                          	30625
#define QM_REG_MAXPQSIZETXSEL_21_RT_OFFSET                          	30626
#define QM_REG_MAXPQSIZETXSEL_22_RT_OFFSET                          	30627
#define QM_REG_MAXPQSIZETXSEL_23_RT_OFFSET                          	30628
#define QM_REG_MAXPQSIZETXSEL_24_RT_OFFSET                          	30629
#define QM_REG_MAXPQSIZETXSEL_25_RT_OFFSET                          	30630
#define QM_REG_MAXPQSIZETXSEL_26_RT_OFFSET                          	30631
#define QM_REG_MAXPQSIZETXSEL_27_RT_OFFSET                          	30632
#define QM_REG_MAXPQSIZETXSEL_28_RT_OFFSET                          	30633
#define QM_REG_MAXPQSIZETXSEL_29_RT_OFFSET                          	30634
#define QM_REG_MAXPQSIZETXSEL_30_RT_OFFSET                          	30635
#define QM_REG_MAXPQSIZETXSEL_31_RT_OFFSET                          	30636
#define QM_REG_MAXPQSIZETXSEL_32_RT_OFFSET                          	30637
#define QM_REG_MAXPQSIZETXSEL_33_RT_OFFSET                          	30638
#define QM_REG_MAXPQSIZETXSEL_34_RT_OFFSET                          	30639
#define QM_REG_MAXPQSIZETXSEL_35_RT_OFFSET                          	30640
#define QM_REG_MAXPQSIZETXSEL_36_RT_OFFSET                          	30641
#define QM_REG_MAXPQSIZETXSEL_37_RT_OFFSET                          	30642
#define QM_REG_MAXPQSIZETXSEL_38_RT_OFFSET                          	30643
#define QM_REG_MAXPQSIZETXSEL_39_RT_OFFSET                          	30644
#define QM_REG_MAXPQSIZETXSEL_40_RT_OFFSET                          	30645
#define QM_REG_MAXPQSIZETXSEL_41_RT_OFFSET                          	30646
#define QM_REG_MAXPQSIZETXSEL_42_RT_OFFSET                          	30647
#define QM_REG_MAXPQSIZETXSEL_43_RT_OFFSET                          	30648
#define QM_REG_MAXPQSIZETXSEL_44_RT_OFFSET                          	30649
#define QM_REG_MAXPQSIZETXSEL_45_RT_OFFSET                          	30650
#define QM_REG_MAXPQSIZETXSEL_46_RT_OFFSET                          	30651
#define QM_REG_MAXPQSIZETXSEL_47_RT_OFFSET                          	30652
#define QM_REG_MAXPQSIZETXSEL_48_RT_OFFSET                          	30653
#define QM_REG_MAXPQSIZETXSEL_49_RT_OFFSET                          	30654
#define QM_REG_MAXPQSIZETXSEL_50_RT_OFFSET                          	30655
#define QM_REG_MAXPQSIZETXSEL_51_RT_OFFSET                          	30656
#define QM_REG_MAXPQSIZETXSEL_52_RT_OFFSET                          	30657
#define QM_REG_MAXPQSIZETXSEL_53_RT_OFFSET                          	30658
#define QM_REG_MAXPQSIZETXSEL_54_RT_OFFSET                          	30659
#define QM_REG_MAXPQSIZETXSEL_55_RT_OFFSET                          	30660
#define QM_REG_MAXPQSIZETXSEL_56_RT_OFFSET                          	30661
#define QM_REG_MAXPQSIZETXSEL_57_RT_OFFSET                          	30662
#define QM_REG_MAXPQSIZETXSEL_58_RT_OFFSET                          	30663
#define QM_REG_MAXPQSIZETXSEL_59_RT_OFFSET                          	30664
#define QM_REG_MAXPQSIZETXSEL_60_RT_OFFSET                          	30665
#define QM_REG_MAXPQSIZETXSEL_61_RT_OFFSET                          	30666
#define QM_REG_MAXPQSIZETXSEL_62_RT_OFFSET                          	30667
#define QM_REG_MAXPQSIZETXSEL_63_RT_OFFSET                          	30668
#define QM_REG_BASEADDROTHERPQ_RT_OFFSET                            	30669
#define QM_REG_BASEADDROTHERPQ_RT_SIZE                              	128
#define QM_REG_AFULLQMBYPTHRPFWFQ_RT_OFFSET                         	30797
#define QM_REG_AFULLQMBYPTHRVPWFQ_RT_OFFSET                         	30798
#define QM_REG_AFULLQMBYPTHRPFRL_RT_OFFSET                          	30799
#define QM_REG_AFULLQMBYPTHRGLBLRL_RT_OFFSET                        	30800
#define QM_REG_AFULLOPRTNSTCCRDMASK_RT_OFFSET                       	30801
#define QM_REG_WRROTHERPQGRP_0_RT_OFFSET                            	30802
#define QM_REG_WRROTHERPQGRP_1_RT_OFFSET                            	30803
#define QM_REG_WRROTHERPQGRP_2_RT_OFFSET                            	30804
#define QM_REG_WRROTHERPQGRP_3_RT_OFFSET                            	30805
#define QM_REG_WRROTHERPQGRP_4_RT_OFFSET                            	30806
#define QM_REG_WRROTHERPQGRP_5_RT_OFFSET                            	30807
#define QM_REG_WRROTHERPQGRP_6_RT_OFFSET                            	30808
#define QM_REG_WRROTHERPQGRP_7_RT_OFFSET                            	30809
#define QM_REG_WRROTHERPQGRP_8_RT_OFFSET                            	30810
#define QM_REG_WRROTHERPQGRP_9_RT_OFFSET                            	30811
#define QM_REG_WRROTHERPQGRP_10_RT_OFFSET                           	30812
#define QM_REG_WRROTHERPQGRP_11_RT_OFFSET                           	30813
#define QM_REG_WRROTHERPQGRP_12_RT_OFFSET                           	30814
#define QM_REG_WRROTHERPQGRP_13_RT_OFFSET                           	30815
#define QM_REG_WRROTHERPQGRP_14_RT_OFFSET                           	30816
#define QM_REG_WRROTHERPQGRP_15_RT_OFFSET                           	30817
#define QM_REG_WRROTHERGRPWEIGHT_0_RT_OFFSET                        	30818
#define QM_REG_WRROTHERGRPWEIGHT_1_RT_OFFSET                        	30819
#define QM_REG_WRROTHERGRPWEIGHT_2_RT_OFFSET                        	30820
#define QM_REG_WRROTHERGRPWEIGHT_3_RT_OFFSET                        	30821
#define QM_REG_WRRTXGRPWEIGHT_0_RT_OFFSET                           	30822
#define QM_REG_WRRTXGRPWEIGHT_1_RT_OFFSET                           	30823
#define QM_REG_PQTX2PF_0_RT_OFFSET                                  	30824
#define QM_REG_PQTX2PF_1_RT_OFFSET                                  	30825
#define QM_REG_PQTX2PF_2_RT_OFFSET                                  	30826
#define QM_REG_PQTX2PF_3_RT_OFFSET                                  	30827
#define QM_REG_PQTX2PF_4_RT_OFFSET                                  	30828
#define QM_REG_PQTX2PF_5_RT_OFFSET                                  	30829
#define QM_REG_PQTX2PF_6_RT_OFFSET                                  	30830
#define QM_REG_PQTX2PF_7_RT_OFFSET                                  	30831
#define QM_REG_PQTX2PF_8_RT_OFFSET                                  	30832
#define QM_REG_PQTX2PF_9_RT_OFFSET                                  	30833
#define QM_REG_PQTX2PF_10_RT_OFFSET                                 	30834
#define QM_REG_PQTX2PF_11_RT_OFFSET                                 	30835
#define QM_REG_PQTX2PF_12_RT_OFFSET                                 	30836
#define QM_REG_PQTX2PF_13_RT_OFFSET                                 	30837
#define QM_REG_PQTX2PF_14_RT_OFFSET                                 	30838
#define QM_REG_PQTX2PF_15_RT_OFFSET                                 	30839
#define QM_REG_PQTX2PF_16_RT_OFFSET                                 	30840
#define QM_REG_PQTX2PF_17_RT_OFFSET                                 	30841
#define QM_REG_PQTX2PF_18_RT_OFFSET                                 	30842
#define QM_REG_PQTX2PF_19_RT_OFFSET                                 	30843
#define QM_REG_PQTX2PF_20_RT_OFFSET                                 	30844
#define QM_REG_PQTX2PF_21_RT_OFFSET                                 	30845
#define QM_REG_PQTX2PF_22_RT_OFFSET                                 	30846
#define QM_REG_PQTX2PF_23_RT_OFFSET                                 	30847
#define QM_REG_PQTX2PF_24_RT_OFFSET                                 	30848
#define QM_REG_PQTX2PF_25_RT_OFFSET                                 	30849
#define QM_REG_PQTX2PF_26_RT_OFFSET                                 	30850
#define QM_REG_PQTX2PF_27_RT_OFFSET                                 	30851
#define QM_REG_PQTX2PF_28_RT_OFFSET                                 	30852
#define QM_REG_PQTX2PF_29_RT_OFFSET                                 	30853
#define QM_REG_PQTX2PF_30_RT_OFFSET                                 	30854
#define QM_REG_PQTX2PF_31_RT_OFFSET                                 	30855
#define QM_REG_PQTX2PF_32_RT_OFFSET                                 	30856
#define QM_REG_PQTX2PF_33_RT_OFFSET                                 	30857
#define QM_REG_PQTX2PF_34_RT_OFFSET                                 	30858
#define QM_REG_PQTX2PF_35_RT_OFFSET                                 	30859
#define QM_REG_PQTX2PF_36_RT_OFFSET                                 	30860
#define QM_REG_PQTX2PF_37_RT_OFFSET                                 	30861
#define QM_REG_PQTX2PF_38_RT_OFFSET                                 	30862
#define QM_REG_PQTX2PF_39_RT_OFFSET                                 	30863
#define QM_REG_PQTX2PF_40_RT_OFFSET                                 	30864
#define QM_REG_PQTX2PF_41_RT_OFFSET                                 	30865
#define QM_REG_PQTX2PF_42_RT_OFFSET                                 	30866
#define QM_REG_PQTX2PF_43_RT_OFFSET                                 	30867
#define QM_REG_PQTX2PF_44_RT_OFFSET                                 	30868
#define QM_REG_PQTX2PF_45_RT_OFFSET                                 	30869
#define QM_REG_PQTX2PF_46_RT_OFFSET                                 	30870
#define QM_REG_PQTX2PF_47_RT_OFFSET                                 	30871
#define QM_REG_PQTX2PF_48_RT_OFFSET                                 	30872
#define QM_REG_PQTX2PF_49_RT_OFFSET                                 	30873
#define QM_REG_PQTX2PF_50_RT_OFFSET                                 	30874
#define QM_REG_PQTX2PF_51_RT_OFFSET                                 	30875
#define QM_REG_PQTX2PF_52_RT_OFFSET                                 	30876
#define QM_REG_PQTX2PF_53_RT_OFFSET                                 	30877
#define QM_REG_PQTX2PF_54_RT_OFFSET                                 	30878
#define QM_REG_PQTX2PF_55_RT_OFFSET                                 	30879
#define QM_REG_PQTX2PF_56_RT_OFFSET                                 	30880
#define QM_REG_PQTX2PF_57_RT_OFFSET                                 	30881
#define QM_REG_PQTX2PF_58_RT_OFFSET                                 	30882
#define QM_REG_PQTX2PF_59_RT_OFFSET                                 	30883
#define QM_REG_PQTX2PF_60_RT_OFFSET                                 	30884
#define QM_REG_PQTX2PF_61_RT_OFFSET                                 	30885
#define QM_REG_PQTX2PF_62_RT_OFFSET                                 	30886
#define QM_REG_PQTX2PF_63_RT_OFFSET                                 	30887
#define QM_REG_PQOTHER2PF_0_RT_OFFSET                               	30888
#define QM_REG_PQOTHER2PF_1_RT_OFFSET                               	30889
#define QM_REG_PQOTHER2PF_2_RT_OFFSET                               	30890
#define QM_REG_PQOTHER2PF_3_RT_OFFSET                               	30891
#define QM_REG_PQOTHER2PF_4_RT_OFFSET                               	30892
#define QM_REG_PQOTHER2PF_5_RT_OFFSET                               	30893
#define QM_REG_PQOTHER2PF_6_RT_OFFSET                               	30894
#define QM_REG_PQOTHER2PF_7_RT_OFFSET                               	30895
#define QM_REG_PQOTHER2PF_8_RT_OFFSET                               	30896
#define QM_REG_PQOTHER2PF_9_RT_OFFSET                               	30897
#define QM_REG_PQOTHER2PF_10_RT_OFFSET                              	30898
#define QM_REG_PQOTHER2PF_11_RT_OFFSET                              	30899
#define QM_REG_PQOTHER2PF_12_RT_OFFSET                              	30900
#define QM_REG_PQOTHER2PF_13_RT_OFFSET                              	30901
#define QM_REG_PQOTHER2PF_14_RT_OFFSET                              	30902
#define QM_REG_PQOTHER2PF_15_RT_OFFSET                              	30903
#define QM_REG_RLGLBLPERIOD_0_RT_OFFSET                             	30904
#define QM_REG_RLGLBLPERIOD_1_RT_OFFSET                             	30905
#define QM_REG_RLGLBLPERIODTIMER_0_RT_OFFSET                        	30906
#define QM_REG_RLGLBLPERIODTIMER_1_RT_OFFSET                        	30907
#define QM_REG_RLGLBLPERIODSEL_0_RT_OFFSET                          	30908
#define QM_REG_RLGLBLPERIODSEL_1_RT_OFFSET                          	30909
#define QM_REG_RLGLBLPERIODSEL_2_RT_OFFSET                          	30910
#define QM_REG_RLGLBLPERIODSEL_3_RT_OFFSET                          	30911
#define QM_REG_RLGLBLPERIODSEL_4_RT_OFFSET                          	30912
#define QM_REG_RLGLBLPERIODSEL_5_RT_OFFSET                          	30913
#define QM_REG_RLGLBLPERIODSEL_6_RT_OFFSET                          	30914
#define QM_REG_RLGLBLPERIODSEL_7_RT_OFFSET                          	30915
#define QM_REG_RLGLBLINCVAL_RT_OFFSET                               	30916
#define QM_REG_RLGLBLINCVAL_RT_SIZE                                 	256
#define QM_REG_RLGLBLUPPERBOUND_RT_OFFSET                           	31172
#define QM_REG_RLGLBLUPPERBOUND_RT_SIZE                             	256
#define QM_REG_RLGLBLCRD_RT_OFFSET                                  	31428
#define QM_REG_RLGLBLCRD_RT_SIZE                                    	256
#define QM_REG_RLGLBLENABLE_RT_OFFSET                               	31684
#define QM_REG_RLPFPERIOD_RT_OFFSET                                 	31685
#define QM_REG_RLPFPERIODTIMER_RT_OFFSET                            	31686
#define QM_REG_RLPFINCVAL_RT_OFFSET                                 	31687
#define QM_REG_RLPFINCVAL_RT_SIZE                                   	16
#define QM_REG_RLPFUPPERBOUND_RT_OFFSET                             	31703
#define QM_REG_RLPFUPPERBOUND_RT_SIZE                               	16
#define QM_REG_RLPFCRD_RT_OFFSET                                    	31719
#define QM_REG_RLPFCRD_RT_SIZE                                      	16
#define QM_REG_RLPFENABLE_RT_OFFSET                                 	31735
#define QM_REG_RLPFVOQENABLE_RT_OFFSET                              	31736
#define QM_REG_WFQPFWEIGHT_RT_OFFSET                                	31737
#define QM_REG_WFQPFWEIGHT_RT_SIZE                                  	16
#define QM_REG_WFQPFUPPERBOUND_RT_OFFSET                            	31753
#define QM_REG_WFQPFUPPERBOUND_RT_SIZE                              	16
#define QM_REG_WFQPFCRD_RT_OFFSET                                   	31769
#define QM_REG_WFQPFCRD_RT_SIZE                                     	256
#define QM_REG_WFQPFENABLE_RT_OFFSET                                	32025
#define QM_REG_WFQVPENABLE_RT_OFFSET                                	32026
#define QM_REG_BASEADDRTXPQ_RT_OFFSET                               	32027
#define QM_REG_BASEADDRTXPQ_RT_SIZE                                 	512
#define QM_REG_TXPQMAP_RT_OFFSET                                    	32539
#define QM_REG_TXPQMAP_RT_SIZE                                      	512
#define QM_REG_WFQVPWEIGHT_RT_OFFSET                                	33051
#define QM_REG_WFQVPWEIGHT_RT_SIZE                                  	512
#define QM_REG_WFQVPCRD_RT_OFFSET                                   	33563
#define QM_REG_WFQVPCRD_RT_SIZE                                     	512
#define QM_REG_WFQVPMAP_RT_OFFSET                                   	34075
#define QM_REG_WFQVPMAP_RT_SIZE                                     	512
#define QM_REG_WFQPFCRD_MSB_RT_OFFSET                               	34587
#define QM_REG_WFQPFCRD_MSB_RT_SIZE                                 	320
#define QM_REG_VOQCRDLINE_RT_OFFSET                                 	34907
#define QM_REG_VOQCRDLINE_RT_SIZE                                   	36
#define QM_REG_VOQINITCRDLINE_RT_OFFSET                             	34943
#define QM_REG_VOQINITCRDLINE_RT_SIZE                               	36
#define NIG_REG_TAG_ETHERTYPE_0_RT_OFFSET                           	34979
#define NIG_REG_OUTER_TAG_VALUE_LIST0_RT_OFFSET                     	34980
#define NIG_REG_OUTER_TAG_VALUE_LIST1_RT_OFFSET                     	34981
#define NIG_REG_OUTER_TAG_VALUE_LIST2_RT_OFFSET                     	34982
#define NIG_REG_OUTER_TAG_VALUE_LIST3_RT_OFFSET                     	34983
#define NIG_REG_OUTER_TAG_VALUE_MASK_RT_OFFSET                      	34984
#define NIG_REG_LLH_FUNC_TAGMAC_CLS_TYPE_RT_OFFSET                  	34985
#define NIG_REG_LLH_FUNC_TAG_EN_RT_OFFSET                           	34986
#define NIG_REG_LLH_FUNC_TAG_EN_RT_SIZE                             	4
#define NIG_REG_LLH_FUNC_TAG_HDR_SEL_RT_OFFSET                      	34990
#define NIG_REG_LLH_FUNC_TAG_HDR_SEL_RT_SIZE                        	4
#define NIG_REG_LLH_FUNC_TAG_VALUE_RT_OFFSET                        	34994
#define NIG_REG_LLH_FUNC_TAG_VALUE_RT_SIZE                          	4
#define NIG_REG_LLH_FUNC_NO_TAG_RT_OFFSET                           	34998
#define NIG_REG_LLH_FUNC_FILTER_VALUE_RT_OFFSET                     	34999
#define NIG_REG_LLH_FUNC_FILTER_VALUE_RT_SIZE                       	32
#define NIG_REG_LLH_FUNC_FILTER_EN_RT_OFFSET                        	35031
#define NIG_REG_LLH_FUNC_FILTER_EN_RT_SIZE                          	16
#define NIG_REG_LLH_FUNC_FILTER_MODE_RT_OFFSET                      	35047
#define NIG_REG_LLH_FUNC_FILTER_MODE_RT_SIZE                        	16
#define NIG_REG_LLH_FUNC_FILTER_PROTOCOL_TYPE_RT_OFFSET             	35063
#define NIG_REG_LLH_FUNC_FILTER_PROTOCOL_TYPE_RT_SIZE               	16
#define NIG_REG_LLH_FUNC_FILTER_HDR_SEL_RT_OFFSET                   	35079
#define NIG_REG_LLH_FUNC_FILTER_HDR_SEL_RT_SIZE                     	16
#define NIG_REG_TX_EDPM_CTRL_RT_OFFSET                              	35095
#define NIG_REG_ROCE_DUPLICATE_TO_HOST_RT_OFFSET                    	35096
#define CDU_REG_CID_ADDR_PARAMS_RT_OFFSET                           	35097
#define CDU_REG_SEGMENT0_PARAMS_RT_OFFSET                           	35098
#define CDU_REG_SEGMENT1_PARAMS_RT_OFFSET                           	35099
#define CDU_REG_PF_SEG0_TYPE_OFFSET_RT_OFFSET                       	35100
#define CDU_REG_PF_SEG1_TYPE_OFFSET_RT_OFFSET                       	35101
#define CDU_REG_PF_SEG2_TYPE_OFFSET_RT_OFFSET                       	35102
#define CDU_REG_PF_SEG3_TYPE_OFFSET_RT_OFFSET                       	35103
#define CDU_REG_PF_FL_SEG0_TYPE_OFFSET_RT_OFFSET                    	35104
#define CDU_REG_PF_FL_SEG1_TYPE_OFFSET_RT_OFFSET                    	35105
#define CDU_REG_PF_FL_SEG2_TYPE_OFFSET_RT_OFFSET                    	35106
#define CDU_REG_PF_FL_SEG3_TYPE_OFFSET_RT_OFFSET                    	35107
#define CDU_REG_VF_SEG_TYPE_OFFSET_RT_OFFSET                        	35108
#define CDU_REG_VF_FL_SEG_TYPE_OFFSET_RT_OFFSET                     	35109
#define PBF_REG_TAG_ETHERTYPE_0_RT_OFFSET                           	35110
#define PBF_REG_BTB_SHARED_AREA_SIZE_RT_OFFSET                      	35111
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ0_RT_OFFSET                    	35112
#define PBF_REG_BTB_GUARANTEED_VOQ0_RT_OFFSET                       	35113
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ0_RT_OFFSET                	35114
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ1_RT_OFFSET                    	35115
#define PBF_REG_BTB_GUARANTEED_VOQ1_RT_OFFSET                       	35116
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ1_RT_OFFSET                	35117
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ2_RT_OFFSET                    	35118
#define PBF_REG_BTB_GUARANTEED_VOQ2_RT_OFFSET                       	35119
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ2_RT_OFFSET                	35120
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ3_RT_OFFSET                    	35121
#define PBF_REG_BTB_GUARANTEED_VOQ3_RT_OFFSET                       	35122
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ3_RT_OFFSET                	35123
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ4_RT_OFFSET                    	35124
#define PBF_REG_BTB_GUARANTEED_VOQ4_RT_OFFSET                       	35125
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ4_RT_OFFSET                	35126
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ5_RT_OFFSET                    	35127
#define PBF_REG_BTB_GUARANTEED_VOQ5_RT_OFFSET                       	35128
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ5_RT_OFFSET                	35129
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ6_RT_OFFSET                    	35130
#define PBF_REG_BTB_GUARANTEED_VOQ6_RT_OFFSET                       	35131
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ6_RT_OFFSET                	35132
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ7_RT_OFFSET                    	35133
#define PBF_REG_BTB_GUARANTEED_VOQ7_RT_OFFSET                       	35134
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ7_RT_OFFSET                	35135
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ8_RT_OFFSET                    	35136
#define PBF_REG_BTB_GUARANTEED_VOQ8_RT_OFFSET                       	35137
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ8_RT_OFFSET                	35138
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ9_RT_OFFSET                    	35139
#define PBF_REG_BTB_GUARANTEED_VOQ9_RT_OFFSET                       	35140
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ9_RT_OFFSET                	35141
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ10_RT_OFFSET                   	35142
#define PBF_REG_BTB_GUARANTEED_VOQ10_RT_OFFSET                      	35143
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ10_RT_OFFSET               	35144
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ11_RT_OFFSET                   	35145
#define PBF_REG_BTB_GUARANTEED_VOQ11_RT_OFFSET                      	35146
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ11_RT_OFFSET               	35147
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ12_RT_OFFSET                   	35148
#define PBF_REG_BTB_GUARANTEED_VOQ12_RT_OFFSET                      	35149
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ12_RT_OFFSET               	35150
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ13_RT_OFFSET                   	35151
#define PBF_REG_BTB_GUARANTEED_VOQ13_RT_OFFSET                      	35152
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ13_RT_OFFSET               	35153
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ14_RT_OFFSET                   	35154
#define PBF_REG_BTB_GUARANTEED_VOQ14_RT_OFFSET                      	35155
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ14_RT_OFFSET               	35156
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ15_RT_OFFSET                   	35157
#define PBF_REG_BTB_GUARANTEED_VOQ15_RT_OFFSET                      	35158
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ15_RT_OFFSET               	35159
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ16_RT_OFFSET                   	35160
#define PBF_REG_BTB_GUARANTEED_VOQ16_RT_OFFSET                      	35161
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ16_RT_OFFSET               	35162
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ17_RT_OFFSET                   	35163
#define PBF_REG_BTB_GUARANTEED_VOQ17_RT_OFFSET                      	35164
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ17_RT_OFFSET               	35165
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ18_RT_OFFSET                   	35166
#define PBF_REG_BTB_GUARANTEED_VOQ18_RT_OFFSET                      	35167
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ18_RT_OFFSET               	35168
#define PBF_REG_YCMD_QS_NUM_LINES_VOQ19_RT_OFFSET                   	35169
#define PBF_REG_BTB_GUARANTEED_VOQ19_RT_OFFSET                      	35170
#define PBF_REG_BTB_SHARED_AREA_SETUP_VOQ19_RT_OFFSET               	35171
#define XCM_REG_CON_PHY_Q3_RT_OFFSET                                	35172

#define RUNTIME_ARRAY_SIZE 35173

#endif /* __RT_DEFS_H__ */
