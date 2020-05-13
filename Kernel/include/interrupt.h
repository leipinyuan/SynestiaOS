#ifndef __KERNEL_INTERRUPT_H__
#define __KERNEL_INTERRUPT_H__

#include <stdint.h>

// #define ARM_INTERRUPT_REGISTER_BASE 0x7E00B000
#define ARM_INTERRUPT_REGISTER_BASE 0x3F00B000
#define RPI_INTERRUPT_CONTROLLER_BASE   (ARM_INTERRUPT_REGISTER_BASE+0x0200)

typedef struct {
    volatile  uint32_t IRQ_basic_pending;
    volatile  uint32_t IRQ_pending_1;
    volatile  uint32_t IRQ_pending_2;
    volatile  uint32_t FIQ_control;
    volatile  uint32_t Enable_IRQs_1;
    volatile  uint32_t Enable_IRQs_2;
    volatile  uint32_t Enable_Basic_IRQs;
    volatile  uint32_t Disable_IRQs_1;
    volatile  uint32_t Disable_IRQs_2;
    volatile  uint32_t Disable_Basic_IRQs;
} rpi_irq_controller_t;

/**
 * get interrupt controller from memory
 * @return
 */
rpi_irq_controller_t* getIRQController(void);


/**
 * init interrupt
 */
void init_interrupt();

/**
 * check interrupt status form cpsr register
 * @return
 */
uint32_t is_interrupt_enabled();

/**
 * enable interrupt with cpsie
 */
void enable_interrupt();

/**
 * disable instrrupt with cpsid
 */
void disable_interrupt();

/**
 * register interrupt
 * @param interrupt_no
 * @param interrupt_handler_f
 * @param interrupt_clear_f
 */
void register_interrupt_handler(uint32_t interrupt_no,void(*interrupt_handler_func)(void),void(*interrupt_clear_func)(void));

/**
 * trigger a software interrupt
 * @param num
 */
void swi(uint32_t num);

#endif // __KERNEL_INTERRUPT_H__
