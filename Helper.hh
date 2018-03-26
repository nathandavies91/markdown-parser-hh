<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown;

class Helper
{
	/**
	 * @var array
	 * An array of block elements represented by their Helper class
	 */
	public static array $blockElements = array(
		// Content, simple
		__NAMESPACE__ . "\\Helpers\\Blockquote",
		__NAMESPACE__ . "\\Helpers\\Heading",
		__NAMESPACE__ . "\\Helpers\\LineBreak",

		// Lists
		__NAMESPACE__ . "\\Helpers\\OrderedList",
		__NAMESPACE__ . "\\Helpers\\UnorderedList",

		// Media
		__NAMESPACE__ . "\\Helpers\\Figure",
		__NAMESPACE__ . "\\Helpers\\YouTube",

		// HTML
		__NAMESPACE__ . "\\Helpers\\Html"
	);

	/**
	 * @var array
	 * An array of inline elements represented by their Helper class
	 */
	public static array $inlineElements = array(
		// Code
		__NAMESPACE__ . "\\Helpers\\Code",

		// Inline styles
		__NAMESPACE__ . "\\Helpers\\Highlight",
		__NAMESPACE__ . "\\Helpers\\Strong",
		__NAMESPACE__ . "\\Helpers\\Emphasis",
		__NAMESPACE__ . "\\Helpers\\LineThrough",

		// Links
		__NAMESPACE__ . "\\Helpers\\Link",

		// Media
		__NAMESPACE__ . "\\Helpers\\Image",

		// Semantic enhancements
		__NAMESPACE__ . "\\Helpers\\Reference",
		__NAMESPACE__ . "\\Helpers\\Time"
	);

	/**
	 * Retrieve helper for type
	 * @param string $type Type
	 * @return string Reference
	 */
	public static function getHelper(string $type): string
	{
		return __NAMESPACE__ . "\\Helpers\\" . $type;
	}

	/**
	 * Default markup functionality
	 * @param array<string>/string $content Content split into it's lines
	 * @param string $tag The HTML tag, for example "p" for paragraph
	 * @return string The markup
	 */
	public static function markup($content, string $tag) : string
	{
		// Make sure there is actually some content
		$content = trim(is_array($content) ? implode("\n", $content) : $content);
		if (!strlen($content)) return "";

		// Attributes
		if (substr($content, -1) == "}" && strpos($content, "{") !== false)
		{
			$regex = "/\{(?<attributes>[^\{]+)\}$/";

			// Extract the attributes and remove from content
			preg_match($regex, $content, $r);
			$content = trim(preg_split($regex, $content)[0]);

			// Tidy up
			foreach (explode(" ", $r["attributes"]) as $attribute)
			{
				// .Class and id support
				$attribute = preg_replace("/^\.(.*)/", "class=$1", $attribute);
				$attribute = preg_replace("/^#(.*)/", "id=$1", $attribute);

				// Key / Value pair
				$attribute = explode("=", $attribute);

				// Make sure we aren't pilling up ids
				if ($attribute[0] == "id")
					$attributes["id"] = @$attribute[1];
				else
					$attributes[$attribute[0]] .= " " . @$attribute[1];
			}

			// Update markup
			foreach ($attributes as $key => $value)
				$tagAttributes .= " " . $key . (($value = trim($value)) ? "=\"" . $value . "\"" : "");
		}

		return "<".$tag.$tagAttributes.">" . $content . "</".$tag.">";
	}

	/**
	 * Parse the regex
	 * @param string $regex The regex
	 * @param string The content to clean up
	 * @return array<string> Matches
	 */
	public static function parse(string $regex, string $content) : array<string>
	{
		preg_match($regex, $content, $matches);
		return $matches;
	}
}
