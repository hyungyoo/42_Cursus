# cpp_module_00

## 파라미터값, 반환값은 전부다 참조자 + const
> std::string의 타입으로 반한이나, 파라마티로서 받을때에는, 무조건 const &의 형태로써야한다. 
자원의 낭비가 줄게된다. 그러나 참조값을 넘기는것은 값의 변화가 일어날수있기때문에, const를 붙여서 주도록한다.