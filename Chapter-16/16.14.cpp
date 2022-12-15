// based on ex7.32
#include <string>
#include <vector>
#include <iostream>
#include <cctype>

template <std::string::size_type height, std::string::size_type width>
class Screen;

class Window_mgr {
public:
  using FixedScreen = Screen<24, 80>;
  using screen_index = std::vector<FixedScreen>::size_type;
  void clear(screen_index);
  Window_mgr();

private:
  std::vector<FixedScreen> screens;
};

// the Screen size is fixed at run time
template <std::string::size_type height, std::string::size_type width>
class Screen {
  friend void Window_mgr::clear(screen_index);

public:
  using size_type = std::string::size_type;
  using content_type = char;

  explicit Screen(content_type c = ' ')
      : cursor(0), contents(height * width, c) { }

  const content_type &get() const { return contents[cursor]; }
  //content_type &get() { return contents[cursor]; }
  const content_type &get(size_type row, size_type col) const;
  //content_type &get(size_type row, size_type col);

  Screen &set(content_type c);
  Screen &set(size_type row, size_type col, content_type c);

  Screen &move(size_type row, size_type col);

  const Screen &display(std::ostream &os) const;
  Screen &display(std::ostream &os);

private:
  void do_display(std::ostream &os) const;

  size_type cursor = 0;
  //size_type height = 0;
  //size_type width = 0;
  std::string contents;
};

template <std::string::size_type height, std::string::size_type width>
inline const typename Screen<height, width>::content_type &
Screen<height, width>::get(size_type row, size_type col) const {
  return contents[row * width + col];
}

//template <std::string::size_type height, std::string::size_type width>
//inline typename Screen<height, width>::content_type &
//Screen<height, width>::get(size_type row, size_type col) {
//  return contents[row * width + col];
//}

template <std::string::size_type height, std::string::size_type width>
inline
Screen<height, width> &Screen<height, width>::set(content_type c) {
  contents[cursor] = c;
  return *this;
}

template <std::string::size_type height, std::string::size_type width>
inline Screen<height, width> &
Screen<height, width>::set(size_type row, size_type col, content_type c) {
  contents[row * width + col] = c;
  return *this;
}

template <std::string::size_type height, std::string::size_type width>
inline Screen<height, width> &
Screen<height, width>::move(size_type row, size_type col) {
  cursor = row * width + col;
  return *this;
}

template <std::string::size_type height, std::string::size_type width>
inline const Screen<height, width> &
Screen<height, width>::display(std::ostream &os) const {
  do_display(os);
  return *this;
}

template <std::string::size_type height, std::string::size_type width>
inline
Screen<height, width> &Screen<height, width>::display(std::ostream &os) {
  do_display(os);
  return *this;
}

template <std::string::size_type height, std::string::size_type width>
inline
void Screen<height, width>::do_display(std::ostream &os) const {
  for (size_type i = 0; i != contents.size(); ++i) {
    os << contents[i];
    if ((i + 1) % width == 0 && i + 1 != contents.size())
      os << "\n";
  }
}

// The input and output operators do not need to be friend of `Screen`, they
// can use the interface of `Screen`.
template <std::string::size_type height, std::string::size_type width>
std::ostream &operator<<(std::ostream &os, const Screen<height, width> &s) {
  s.display(os);
  return os;
}

template <std::string::size_type height, std::string::size_type width>
std::istream &operator>>(std::istream &is, Screen<height, width> &s) {
  char ch;
  for (Screen<height, width>::size_type i = 0; i != height; ++i)
    for (Screen<height, width>::size_type j = 0; j != width; ++j) {
      while (!std::isprint(ch = is.get()));
      s.move(i, j).set(ch);
    }
  return is;
}

Window_mgr::Window_mgr() : screens{FixedScreen()} {}

//void Window_mgr::clear(screen_index i) {
//  FixedScreen &s = screens[i];
//  s.contents = std::string(s.height * s.width, ' ');  // error in template
//}

int main() {
  //Screen myScreen(5, 5, 'X');
  Screen<5, 5> myScreen('X');
  std::cout << myScreen << "\n-----\n";
  myScreen.move(4,0).set('#').display(std::cout);
  std::cout << "\n-----\n" << myScreen << "\n-----\n";
  std::cin >> myScreen;
  std::cout << "\n-----\n" << myScreen << "\n-----\n";

  Screen<2, 3> myScreen2;
  const Screen<2, 3> blank;
  myScreen2.set('#').display(std::cout);  // calls nonconst version
  std::cout << "\n-----\n";
  blank.display(std::cout);  // calls const version
  std::cout << "\n-----\n";

  Window_mgr window;
  //window.clear(0);

  return 0;
}
