<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown;

use Markdown\Parser\Chunk;

class Parser
{
	private array<Chunk> $chunks;

	/**
	 * Initiate content parsing; split the content into relevant chunks
	 * @param string $content The content to be parsed
	 * @return string The markup; parsed content
	 */
	public function parse(string $content) : string
	{
		// Split content into relevant chunks
		foreach (preg_split("/[\n]{2,}/", str_replace(array("\r", "\r\n"), "\n", $content)) as $chunk)
			$this->chunks []= new Chunk($chunk);

		foreach ($this->chunks as $chunk)
			@$markup .= $chunk->markup();

		return $markup;
	}
}
