import streamlit as st
from PIL import Image
from streamlit_drawable_canvas import st_canvas

# Tiêu đề chính
st.title("Digit Recognition")

# Tiêu đề cho sidebar và lựa chọn các tuỳ chọn
st.sidebar.title("Options") 
option = st.sidebar.radio("Choose an option:", ("Upload Image", "Draw"))

# Nếu người dùng chọn 'Upload Image'
if option == "Upload Image":
    left, right = st.columns(2)

    with left:
        # Tiêu đề phần Upload
        st.header('Upload a Digit Image')
        
        # Nút để người dùng tải ảnh lên
        uploaded_file = st.file_uploader("Add image", type=["jpg", "jpeg", "png"])

    with right:
        if uploaded_file is not None:
            # Mở ảnh được tải lên
            raw_image = Image.open(uploaded_file)
            # Chỉnh sửa kích thước ảnh về 28x28 pixel
            image = raw_image.resize((28, 28), Image.NEAREST)
            # Hiển thị ảnh đã chỉnh sửa kích thước
            st.image(image, caption="Received image")

            if st.button("Submit"):
                st.write('Result = Pé đức thư giãn')

# Nếu người dùng chọn 'Draw'
if option == "Draw":
    left, right = st.columns(2)

    with left:
        # Tiêu đề phần Draw
        st.header('Draw a Digit')

        # Tạo canvas cho người dùng vẽ
        canvas_result = st_canvas(
            fill_color = "rgba(255, 165, 0, 0.3)", # Màu nền của canvas
            stroke_width = 25, # Độ dày nét vẽ 
            stroke_color = "#000000", # Màu của nét vẽ
            background_color = "#FFFFFF", # Màu nền của canvas
            width = 280, # Chiều rộng của canvas
            height = 280, # Chiều cao của canvas
            drawing_mode = "freedraw", # Chế độ vẽ tự do
            key = "canvas" # Khóa cho canvas
        )

    with right:
        if canvas_result.image_data is not None:
            # Chuyển dữ liệu ảnh từ canvas thành đối tượng ảnh PIL
            raw_image = Image.fromarray(canvas_result.image_data.astype('uint8'))
            # Chỉnh sửa kích thước ảnh về 28x28 pixel
            image = raw_image.resize((28, 28), Image.NEAREST)
            # Hiển thị ảnh đã chỉnh sửa kích thước
            st.image(image, caption="Received image")

            if st.button("Submit"):
                st.write('Result = Pé đức thư giãn')
