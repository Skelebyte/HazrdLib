mod hazrd;

use glfw::*;
use hazrd::window;


fn main() {
    println!("Hi mum!");

    let mut my_window: window::HWindow = window::create_window("Hi, mum!", 800, 600);

    while !my_window.glfw_window.should_close() {
        my_window.glfw.poll_events();
        for (_, event) in glfw::flush_messages(&my_window.window_events) {
            match event {
                // glfw::WindowEvent::Key(Key::Escape, _, Action::Press, _) => {
                //     my_window.glfw_window.set_should_close(true)
                // },
                _ => {},
            }
        }

        // rendering
        my_window.glfw_window.swap_buffers();

    }

    println!("stopped");

}