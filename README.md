Thư viện: Tổ chức các danh sách sau

Đầu sách: Danh sách tuyến tính là một mảng con trỏ (ISBN, Tên sách, Số trang, Tác giả, Năm xuất bản, Thể loại, Con trỏ). Con trỏ sẽ trỏ đến các sách thuộc đầu sách tương ứng.

Danh mục sách: Danh sách liên kết đơn (Mã sách, Trạng thái, Vị trí). Mỗi cuốn sách chỉ có một mã duy nhất. Trạng thái của sách bao gồm:

0: cho mượn được,
1: đã có độc giả mượn,
2: sách đã thanh lý.
Danh sách độc giả: Cây nhị phân tìm kiếm (Mã độc giả (số nguyên ngẫu nhiên tự động), Họ, Tên, Phái, Trạng thái của thẻ, Con trỏ). Con trỏ sẽ trỏ đến danh sách các cuốn sách đã và đang mượn.

Danh sách Mượn/Trả: Danh sách liên kết đơn (Mã sách, Ngày mượn, Ngày trả, Trạng thái). Trạng thái:

0: sách đang mượn (chưa trả),
1: đã trả,
2: làm mất sách.
Chương trình có các chức năng sau:

a. Nhập độc giả: Thêm/xóa/hiệu chỉnh thông tin độc giả. Mã độc giả được chương trình tự động lấy ngẫu nhiên và không trùng với các mã độc giả cũ. Phái chỉ nhận 'Nam' hoặc 'Nữ'. Trạng thái thẻ = 0 khi thẻ bị khóa, trạng thái thẻ = 1 khi thẻ đang hoạt động (được quyền mượn sách).

b. In danh sách độc giả: In ra màn hình theo thứ tự tên + họ tăng dần hoặc theo thứ tự mã độc giả tăng dần theo yêu cầu của thủ thư.

c. Nhập đầu sách và đánh mã sách tự động.

d. In danh sách các đầu sách trong thư viện theo thứ tự tên sách tăng dần.

e. Tìm thông tin sách dựa vào tên sách: In ra các thông tin ISBN, tên sách, tác giả, năm xuất bản, thể loại, các mã sách còn có trong thư viện.

f. Mượn sách: Nhập vào mã độc giả, chương trình sẽ liệt kê các sách mà độc giả đang mượn. Mỗi độc giả chỉ được mượn tối đa 3 cuốn, không cho mượn khi giữ 1 sách quá hạn (15 ngày).

g. Trả sách.

h. Liệt kê danh sách các sách mà một độc giả đang mượn.

i. In danh sách độc giả mượn sách quá hạn theo thứ tự thời gian quá hạn giảm dần.

j. In 10 sách có số lượt mượn nhiều nhất.
