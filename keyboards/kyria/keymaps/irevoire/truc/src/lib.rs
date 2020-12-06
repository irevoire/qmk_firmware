#![no_std]
#![no_builtins]
#![feature(lang_items)]
#![crate_type = "staticlib"]
#![allow(dead_code)]

#[panic_handler]
fn my_panic(_info: &core::panic::PanicInfo) -> ! {
    loop {}
}
#[lang = "eh_personality"]
extern "C" fn rust_eh_personality() {}

#[no_mangle]
pub extern "C" fn rust() -> usize {
    42
}
