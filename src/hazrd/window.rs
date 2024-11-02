extern crate glfw;

use glfw::*;

pub struct HWindow {
    // GLFW stuff
    pub glfw: Glfw,
    pub glfw_window: glfw::PWindow,
    pub window_events: GlfwReceiver<(f64, WindowEvent)>,
    
    pub width: i32,
    pub height: i32,
    pub name: String,
}

pub fn create_window(name: &str, w: i32, h: i32) -> HWindow {

    let mut m_glfw = glfw::init(glfw::fail_on_errors).unwrap();



    let (mut window, events) = m_glfw.create_window(w as u32, h as u32, name, glfw::WindowMode::Windowed).expect("failed to create GLFW window.");

    window.make_current();
    window.set_key_polling(true);



    let new_window = HWindow {
        glfw: m_glfw,
        glfw_window: window,
        window_events: events,
        width: w,
        height: h,
        name: name.to_string(),
    };

    return new_window;

}