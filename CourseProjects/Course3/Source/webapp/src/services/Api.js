import Axios from 'axios'
import https from 'https'

export default() =>
{
	return Axios.create(
	{
		baseURL: 'https://localhost:8000',
		withCredentials: false,
		headers:
		{
			'Accept': 'application/json',
			'Content-Type': 'application/json'
		}
	})
}
