#![no_std]
#![no_builtins]
#![crate_type = "staticlib"]
#![allow(dead_code)]

#[panic_handler]
fn my_panic(_info: &core::panic::PanicInfo) -> ! {
    loop {}
}

#[no_mangle]
pub extern "C" fn rust() -> usize {
    42
}
