#![no_std]
#![no_builtins]
#![crate_type = "staticlib"]
#![allow(dead_code)]

#[no_mangle]
pub extern "C" fn rust() -> usize {
    42
}
