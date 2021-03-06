/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/*
 * Copyright 2018 Amazon.com, Inc. or its affiliates.
 */
#ifndef _EFA_REGS_H_
#define _EFA_REGS_H_

enum efa_regs_reset_reason_types {
	EFA_REGS_RESET_NORMAL                       = 0,
	/* Keep alive timeout */
	EFA_REGS_RESET_KEEP_ALIVE_TO                = 1,
	EFA_REGS_RESET_ADMIN_TO                     = 2,
	EFA_REGS_RESET_INIT_ERR                     = 3,
	EFA_REGS_RESET_DRIVER_INVALID_STATE         = 4,
	EFA_REGS_RESET_OS_TRIGGER                   = 5,
	EFA_REGS_RESET_SHUTDOWN                     = 6,
	EFA_REGS_RESET_USER_TRIGGER                 = 7,
	EFA_REGS_RESET_GENERIC                      = 8,
};

/* common_registers offsets */

/* 0x54 base */
#define EFA_REGS_DEV_CTL_OFF                                0x54
#define EFA_REGS_DEV_STS_OFF                                0x58

/* efa_registers offsets */

/* 0x800 base */
#define EFA_REGS_VERSION_OFF                                0x800
#define EFA_REGS_CONTROLLER_VERSION_OFF                     0x804
#define EFA_REGS_CAPS_OFF                                   0x808
#define EFA_REGS_CAPS_EXT_OFF                               0x80c
#define EFA_REGS_AQ_BASE_LO_OFF                             0x810
#define EFA_REGS_AQ_BASE_HI_OFF                             0x814
#define EFA_REGS_AQ_CAPS_OFF                                0x818
#define EFA_REGS_ACQ_BASE_LO_OFF                            0x820
#define EFA_REGS_ACQ_BASE_HI_OFF                            0x824
#define EFA_REGS_ACQ_CAPS_OFF                               0x828
#define EFA_REGS_AQ_PROD_DB_OFF                             0x82c
#define EFA_REGS_AENQ_CAPS_OFF                              0x830
#define EFA_REGS_AENQ_BASE_LO_OFF                           0x834
#define EFA_REGS_AENQ_BASE_HI_OFF                           0x838
#define EFA_REGS_AENQ_CONS_DB_OFF                           0x83c
#define EFA_REGS_INTR_MASK_OFF                              0x844
#define EFA_REGS_MMIO_REG_READ_OFF                          0x84c
#define EFA_REGS_MMIO_RESP_LO_OFF                           0x850
#define EFA_REGS_MMIO_RESP_HI_OFF                           0x854

/* dev_ctl register */
#define EFA_REGS_DEV_CTL_DEV_RESET_MASK                     0x1
#define EFA_REGS_DEV_CTL_AQ_RESTART_SHIFT                   1
#define EFA_REGS_DEV_CTL_AQ_RESTART_MASK                    0x2
#define EFA_REGS_DEV_CTL_RESET_REASON_SHIFT                 28
#define EFA_REGS_DEV_CTL_RESET_REASON_MASK                  0xf0000000

/* dev_sts register */
#define EFA_REGS_DEV_STS_READY_MASK                         0x1
#define EFA_REGS_DEV_STS_AQ_RESTART_IN_PROGRESS_SHIFT       1
#define EFA_REGS_DEV_STS_AQ_RESTART_IN_PROGRESS_MASK        0x2
#define EFA_REGS_DEV_STS_AQ_RESTART_FINISHED_SHIFT          2
#define EFA_REGS_DEV_STS_AQ_RESTART_FINISHED_MASK           0x4
#define EFA_REGS_DEV_STS_RESET_IN_PROGRESS_SHIFT            3
#define EFA_REGS_DEV_STS_RESET_IN_PROGRESS_MASK             0x8
#define EFA_REGS_DEV_STS_RESET_FINISHED_SHIFT               4
#define EFA_REGS_DEV_STS_RESET_FINISHED_MASK                0x10
#define EFA_REGS_DEV_STS_FATAL_ERROR_SHIFT                  5
#define EFA_REGS_DEV_STS_FATAL_ERROR_MASK                   0x20

/* version register */
#define EFA_REGS_VERSION_MINOR_VERSION_MASK                 0xff
#define EFA_REGS_VERSION_MAJOR_VERSION_SHIFT                8
#define EFA_REGS_VERSION_MAJOR_VERSION_MASK                 0xff00

/* controller_version register */
#define EFA_REGS_CONTROLLER_VERSION_SUBMINOR_VERSION_MASK   0xff
#define EFA_REGS_CONTROLLER_VERSION_MINOR_VERSION_SHIFT     8
#define EFA_REGS_CONTROLLER_VERSION_MINOR_VERSION_MASK      0xff00
#define EFA_REGS_CONTROLLER_VERSION_MAJOR_VERSION_SHIFT     16
#define EFA_REGS_CONTROLLER_VERSION_MAJOR_VERSION_MASK      0xff0000
#define EFA_REGS_CONTROLLER_VERSION_IMPL_ID_SHIFT           24
#define EFA_REGS_CONTROLLER_VERSION_IMPL_ID_MASK            0xff000000

/* caps register */
#define EFA_REGS_CAPS_CONTIGUOUS_QUEUE_REQUIRED_MASK        0x1
#define EFA_REGS_CAPS_RESET_TIMEOUT_SHIFT                   1
#define EFA_REGS_CAPS_RESET_TIMEOUT_MASK                    0x3e
#define EFA_REGS_CAPS_DMA_ADDR_WIDTH_SHIFT                  8
#define EFA_REGS_CAPS_DMA_ADDR_WIDTH_MASK                   0xff00
#define EFA_REGS_CAPS_ADMIN_CMD_TO_SHIFT                    16
#define EFA_REGS_CAPS_ADMIN_CMD_TO_MASK                     0xf0000

/* aq_caps register */
#define EFA_REGS_AQ_CAPS_AQ_DEPTH_MASK                      0xffff
#define EFA_REGS_AQ_CAPS_AQ_ENTRY_SIZE_SHIFT                16
#define EFA_REGS_AQ_CAPS_AQ_ENTRY_SIZE_MASK                 0xffff0000

/* acq_caps register */
#define EFA_REGS_ACQ_CAPS_ACQ_DEPTH_MASK                    0xffff
#define EFA_REGS_ACQ_CAPS_ACQ_ENTRY_SIZE_SHIFT              16
#define EFA_REGS_ACQ_CAPS_ACQ_ENTRY_SIZE_MASK               0xff0000
#define EFA_REGS_ACQ_CAPS_ACQ_MSIX_VECTOR_SHIFT             24
#define EFA_REGS_ACQ_CAPS_ACQ_MSIX_VECTOR_MASK              0xff000000

/* aenq_caps register */
#define EFA_REGS_AENQ_CAPS_AENQ_DEPTH_MASK                  0xffff
#define EFA_REGS_AENQ_CAPS_AENQ_ENTRY_SIZE_SHIFT            16
#define EFA_REGS_AENQ_CAPS_AENQ_ENTRY_SIZE_MASK             0xff0000
#define EFA_REGS_AENQ_CAPS_AENQ_MSIX_VECTOR_SHIFT           24
#define EFA_REGS_AENQ_CAPS_AENQ_MSIX_VECTOR_MASK            0xff000000

/* mmio_reg_read register */
#define EFA_REGS_MMIO_REG_READ_REQ_ID_MASK                  0xffff
#define EFA_REGS_MMIO_REG_READ_REG_OFF_SHIFT                16
#define EFA_REGS_MMIO_REG_READ_REG_OFF_MASK                 0xffff0000

#endif /*_EFA_REGS_H_ */
